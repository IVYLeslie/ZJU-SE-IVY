//
//  ContentView.swift
//  HW2_demo
//
//  Created by 朱雨珂 on 2022/4/27.
//

/*
See LICENSE folder for this sample’s licensing information.

Abstract:
RealityKit Object Creation command line tools.
*/

import Foundation
import os
import RealityKit
import Metal
import QuickLook
import SwiftUI

//struct PreviewController: UIViewControllerRepresentable {
//    let url: URL
//
//    func makeUIViewController(context: Context) -> QLPreviewController {
//        let controller = QLPreviewController()
//        controller.dataSource = context.coordinator
//        return controller
//    }
//
//    func makeCoordinator() -> Coordinator {
//        return Coordinator(parent: self)
//    }
//
//    func updateUIViewController(
//        _ uiViewController: QLPreviewController, context: Context) {}
//
//    class Coordinator: QLPreviewControllerDataSource { ... }
//}

struct ContentView: View {

    @State var order = "sequential"
    @State var feature = "normal"
    @State var result = "FileFolder"
    @State var detailextend = "preview"
    @State var input=""
    @State var output=""
        
    @State private var showingPreview = false
    @State private var load=""
    
    private typealias Configuration = PhotogrammetrySession.Configuration
    private typealias Request = PhotogrammetrySession.Request
    static let logger = Logger(subsystem: "com.apple.sample.photogrammetry",
                                category: "HelloPhotogrammetry")
    
    @State private var featureSensitivity: Configuration.FeatureSensitivity?
    @State private var detail: Request.Detail? = nil
    @State private var sampleOrdering: Configuration.SampleOrdering?
    
    private func supportsObjectReconstruction() -> Bool {
        for device in MTLCopyAllDevices() where
            !device.isLowPower &&
             device.areBarycentricCoordsSupported &&
             device.recommendedMaxWorkingSetSize >= UInt64(4e9) {
            return true
        }
        return false
    }

    /// Returns `true` if at least one GPU has hardware support for ray tracing. The GPU that supports ray
    /// tracing need not be the same GPU that supports object reconstruction.
    private func supportsRayTracing() -> Bool {
        for device in MTLCopyAllDevices() where device.supportsRaytracing {
            return true
        }
        return false
    }

    /// Returns `true` if the current hardware supports Object Capture.
    func supportsObjectCapture() -> Bool {
        return supportsObjectReconstruction() && supportsRayTracing()
    }
    
    private func makeConfigurationFromInfo() -> PhotogrammetrySession.Configuration {
        var configuration = PhotogrammetrySession.Configuration()
        sampleOrdering.map { configuration.sampleOrdering = $0 }
        featureSensitivity.map { configuration.featureSensitivity = $0 }
        return configuration
    }
    
    private func makeRequestFromInfo() -> PhotogrammetrySession.Request {
        if result == "usdzFile"{
            output=output+"/result.usdz"
        }
        let outputUrl = URL(fileURLWithPath: output)
            if let detailSetting = detail{
                    return PhotogrammetrySession.Request.modelFile(url: outputUrl, detail: detailSetting)
            }
            else{
                return PhotogrammetrySession.Request.modelFile(url: outputUrl)
            }
        
    }
    
    private static func handleRequestComplete(request: PhotogrammetrySession.Request,result: PhotogrammetrySession.Result) {
        logger.log("Request complete: \(String(describing: request)) with result...")
        //load="Request complete: \(String(describing: request)) with result..."
        switch result {
            case .modelFile(let url):
                logger.log("\tmodelFile available at url=\(url)")
                //load="\tmodelFile available at url=\(url)"
            default:
                logger.warning("\tUnexpected result: \(String(describing: result))")
                //load="\tUnexpected result: \(String(describing: result))"
        }
    }
    
    /// Called when the sessions sends a progress update message.
    private static func handleRequestProgress(request: PhotogrammetrySession.Request,
                                              fractionComplete: Double) {
        logger.log("Progress(request = \(String(describing: request)) = \(fractionComplete)")
    }
    
    func run() {
        guard supportsObjectCapture() else {
            ContentView.logger.error("Program terminated early because the hardware doesn't support Object Capture.")
            print("Object Capture is not available on this computer.")
            Foundation.exit(1)
        }
        
        let inputFolderUrl = URL(fileURLWithPath: input, isDirectory: true)
        
        let configuration = makeConfigurationFromInfo()
        ContentView.logger.log("Using configuration: \(String(describing: configuration))")
        
        // Try to create the session, or else exit.
        var maybeSession: PhotogrammetrySession? = nil
        do {
            maybeSession = try PhotogrammetrySession(input: inputFolderUrl,
                                                     configuration: configuration)
            ContentView.logger.log("Successfully created session.")
        } catch {
            ContentView.logger.error("Error creating session: \(String(describing: error))")
            Foundation.exit(1)
        }
        guard let session = maybeSession else {
            Foundation.exit(1)
            
            
        }
        
        let waiter = Task {
            do {
                for try await output in session.outputs {
                    switch output {
                        case .processingComplete:
                        ContentView.logger.log("Processing is complete!")
                        load="Processing is complete!"
                        case .requestError(let request, let error):
                        ContentView.logger.error("""
                                                 Request \(String(describing: request))
                                                 had an error: \(String(describing: error))
                                                """)
                        load="Request \(String(describing: request))had an error: \(String(describing: error))"
                        case .requestComplete(let request, let result):
                        ContentView.handleRequestComplete(request: request, result: result)
                        case .requestProgress(let request, let fractionComplete):
                        ContentView.handleRequestProgress(request: request,fractionComplete: fractionComplete)
                        case .inputComplete:  // data ingestion only!
                        ContentView.logger.log("Data ingestion is complete.  Beginning processing...")
                        load="Data ingestion is complete.  Beginning processing..."
                        case .invalidSample(let id, let reason):
                        ContentView.logger.warning("Invalid Sample! id=\(id)  reason=\"\(reason)\"")
                        load="Invalid Sample! id=\(id)  reason=\"\(reason)\""
                        case .skippedSample(let id):
                        ContentView.logger.warning("Sample id=\(id) was skipped by processing.")
                        case .automaticDownsampling:
                        ContentView.logger.warning("Automatic downsampling was applied!")
                        case .processingCancelled:
                        ContentView.logger.warning("Processing was cancelled.")
                        @unknown default:
                        ContentView.logger.error("Output: unhandled message: \(output.localizedDescription)")
                    }
                }
            } catch {
                ContentView.logger.error("Output: ERROR = \(String(describing: error))")
                Foundation.exit(0)
            }
        }
        
        // The compiler may deinitialize these objects since they may appear to be
        // unused. This keeps them from being deallocated until they exit.
        withExtendedLifetime((session, waiter)) {
            // Run the main process call on the request, then enter the main run
            // loop until you get the published completion event or error.
            do {
                let request = makeRequestFromInfo()
                ContentView.logger.log("Using request: \(String(describing: request))")
                try session.process(requests: [ request ])
                RunLoop.main.run()
            } catch {
                ContentView.logger.critical("Process got error: \(String(describing: error))")
                Foundation.exit(1)
            }
        }
    }
    
    var body: some View{
        GeometryReader{ geometry in
        HStack{
            Spacer()
            VStack{
                HStack{
                    Text("请输入导入文件夹所在位置")
                    TextField("import url", text: $input).frame(width: 200)
                    Spacer()
                }.frame(width: 400)
                HStack{
                    Text("请输入导出文件所在位置")
                    TextField("export url", text: $output).frame(width: 200)
                    Spacer()
                }.frame(width: 400)
                
                Picker("请选择图片录入的顺序(默认sequential）", selection: $order) {
                    Text("sequential").tag("sequential")
                    Text("unordered").tag("unordered")
                    
                }.frame(width: 400)
                
                Picker("请选择对样本自动补全的程度（默认normal）", selection: $feature) {
                    Text("normal").tag("normal")
                    Text("high").tag("high")
                    
                }.frame(width: 400)
                Picker("请选择要输出的格式（默认FileFolder)", selection: $result) {
                    Text("FileFolder").tag("FileFolder")
                    Text("usdzFile").tag("usdzFile")
                    //Text("modelEntity").tag("modelEntity")
                    //Text("bounds").tag("bounds")
                    
                }.frame(width: 400)
                Picker("请选择模型详细程度(默认preview）", selection: $detailextend) {
                    Text("raw").tag("raw")
                    Text("full").tag("full")
                    Text("medium").tag("medium")
                    Text("reduced").tag("reduced")
                    Text("preview").tag("preview")
                    
                }.frame(width: 400)
                Button(action: {
                    switch detailextend{
                        case "raw" : detail = .raw
                        case "full": detail = .full
                        case "medium": detail = .medium
                        case "reduced": detail = .reduced
                        case "preview": detail = .preview
                    default: detail = .preview
                    }
                    if feature == "normal"{
                        featureSensitivity = .normal
                    }
                    else if feature == "high" {
                        featureSensitivity = .high
                    }
                    
                    if order == "sequential"{
                        sampleOrdering = .sequential
                    }
                    else if order == "unordered"{
                        sampleOrdering = .unordered
                    }
                    
                    run()
                }, label: {Text("生成模型")})
                
                Text(load)
            }.padding(20)
            Spacer()
                
                
                
                
//                Button("Preview File") {
//                            self.showingPreview = true
//                        }
//                        .sheet(isPresented: $showingPreview) {
//                            PreviewController(url: self.fileUrl)
//
//                            }
            
        }.frame(width: geometry.size.width, height: geometry.size.height)
        }
        
        
    }

}
struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}

private enum IllegalOption: Swift.Error {
    case invalidDetail(String)
    case invalidSampleOverlap(String)
    case invalidSampleOrdering(String)
    case invalidFeatureSensitivity(String)
}

@available(macOS 12.0, *)
extension PhotogrammetrySession.Request.Detail {
    init(_ detail: String) throws {
        switch detail {
            case "preview": self = .preview
            case "reduced": self = .reduced
            case "medium": self = .medium
            case "full": self = .full
            case "raw": self = .raw
            default: throw IllegalOption.invalidDetail(detail)
        }
    }
}

@available(macOS 12.0, *)
extension PhotogrammetrySession.Configuration.SampleOrdering {
    init(sampleOrdering: String) throws {
        if sampleOrdering == "unordered" {
            self = .unordered
        } else if sampleOrdering == "sequential" {
            self = .sequential
        } else {
            throw IllegalOption.invalidSampleOrdering(sampleOrdering)
        }
    }
    
}

@available(macOS 12.0, *)
extension PhotogrammetrySession.Configuration.FeatureSensitivity {
    init(featureSensitivity: String) throws {
        if featureSensitivity == "normal" {
            self = .normal
        } else if featureSensitivity == "high" {
            self = .high
        } else {
            throw IllegalOption.invalidFeatureSensitivity(featureSensitivity)
        }
    }
}
