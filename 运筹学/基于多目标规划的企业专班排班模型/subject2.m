
%自定义参数
clear
global N
global IDtotal
global ID2total
global d1total
global d2total
global n
global w3
global w2
global w1
global w0
global schedule
global totalday_rate
global arrange_num
global sumday

N=15;%表示一共15个人

IDtotal=[1 2 3 4 5 6 7 8 9 10 11 12 13 14 15;
    1 1 1 1 1 1 1 0 0 0 1 0 1 0 1;
    -1 -1 -1 0 0 1 0 1 0 -1 -1 -1 -1 -1 -1;
    1 1 1 1 1 1 1 1 1 0 0 0 0 0 0];%第一行表示编号；第二行1表示有驾照；第三行1表示历史事故多，0是不多不少，-1是事故少；第四行1代表有专班经验
ID2total=[2 1 1 1 2 1 1 1 0 0 0 0 0 0 0;
    0 1 2 1 1 1 1 0 0 0 0 0 0 0 0;
    0 0 1 1 0 1 0 1 1 0 0 0 0 0 0;
    0 0 0 0 1 1 0 0 1 0 0 0 0 0 0;
    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15];%第一行表示在A班的历史次数；第五行表示编号
d1total=[6;11;9;10;13;15;6;10;5;10;6;10;4;8;5];%表示工作天数
d2total=[4;6;8;5;8;11;4;5;3;1;-2;-3;-5;-5;-6];%表示已工作天数

n=4;%表示不等式类不确定条件数
w3=10^3;%表示各偏差的权重系数
w2=10^2;
w1=10^1;
w0=10^0;

totalday=10;%一共计算几天
xtotal=zeros(N*4+1,totalday);%前num*s行记录排班，num*s+1行记录当天人数num
x=zeros(1,N*4);
s=0;
num=0;

%----------------------------公平问题----------------------------------
d1_d2total=d1total-d2total;%第n号元素大于零代表第n个人还没离职
sumday=sum(d1total());%所有人总工作天数之和
totalday_rate=d1total/sumday;%每个人总工作天数之和与所有人总工作天数之和比率,N列向量
%求最大排班天数daymax
d1_d2total_sorted=sort(d1_d2total);
daymax=d1_d2total_sorted(length(d1_d2total_sorted)-4);
%求总安排人次
schedule=zeros(N,daymax);
d2totalx=d2total; %为了不改变全局变量
for k1=1:N
    for k2=1:daymax
        if d1_d2total(k1)>0
            if d2totalx(k1)>=0 %当日在工作
                schedule(k1,k2)=1;
                d1_d2total(k1)=d1_d2total(k1)-1;
            else %还未轮到
                d2totalx(k1)=d2totalx(k1)+1;
                d1_d2total(k1)=d1_d2total(k1)-1;
            end
        end
    end
end
sum_everyday=sum(schedule,1);%第k列代表第k天总人数
arrange_num=0; %表示总安排人次
for k=1:daymax
    if sum_everyday(k)>=5 && sum_everyday(k)<8
        arrange_num=arrange_num+2;
    elseif sum_everyday(k)>=8 && sum_everyday(k)<11
        arrange_num=arrange_num+4;
    elseif sum_everyday(k)>=11 && sum_everyday(k)<13
        arrange_num=arrange_num+6;
    elseif sum_everyday(k)>=13 && sum_everyday(k)<16
        arrange_num=arrange_num+8;
    end
end
arrange_num=arrange_num+sum(sum(ID2total(1:4,:)));

for k=1:totalday
    [x,s,num]=daily4(k); 
    xtotal(1:num*s,k)=x(1:num*s);%记录第k天输出
    xtotal(num*s+1,k)=num;
end


%定义第一种公平:使每位员工当前工作天数与当前累计安排专班次数之比尽可能均衡
function [r_k,target_rate]=fair1(num,s,ID2,d2)
%比例rate  
sum1=sum(ID2(1:4,1:num),1); %求每人已安排班次之和
d22=d2(1:num)';
r=sum1./d22;
for k=1:num
    if d22(k)==0
        r(k)=1; %新来的员工先不给他安排
    end
end
r_kx=[r r r r];
r_k=r_kx(1,1:num*s);
minrate=sort(r);
target_rate=sum(minrate(:,1:2*s),2);
end

%定义第二种公平:在企业全部工作期间的工作天数与当前累计专班次数之比尽可能均衡
function [r_k,target_rate]=fair2(num,s,ID2,d1)
%比例rate  
sum1=sum(ID2(1:4,1:num),1); %求每人已安排班次之和
d11=d1(1:num)';
r=sum1./d11;
for k=1:num
    if d11(k)==0
        r(k)=1; %新来的员工先不给他安排
    end
end
r_kx=[r r r r];
r_k=r_kx(1,1:num*s);
minrate=sort(r);
target_rate=sum(minrate(:,1:2*s),2);
end

%定义每天的函数
function [x,s,num]=daily4(day)
global N
global IDtotal
global ID2total
global d1total
global d2total
global n
global w3
global w2
global w1
global w0

d1_d2total=d1total-d2total;%第n号元素大于零代表第n个人还没离职
ID=0;
ID2=0;
d2=0;
%num表示本日车间人数
num=0;
for k=1:N
    if (d2total(k)>=0) && (d1_d2total(k)>0) %第k个人正在工作
        num=num+1;
        if ID==0
            ID=IDtotal(2:4,k);
            ID2=ID2total(1:4,k);
            d1=d1total(k);
            d2=d2total(k);
        else
            ID=[ID IDtotal(2:4,k)];
            ID2=[ID2 ID2total(1:4,k)];
            d1=[d1;d1total(k)];
            d2=[d2;d2total(k)];
        end
    end
end
ID=[[1:num];ID];

%用s（service）表示几趟班车
if num<5
    error('车间少于五个人，排班提前结束');
elseif num>=5 && num<=7
    s=1;
elseif num>=8 && num<=10
    s=2;
elseif num>=11 && num<=12
    s=3;   
elseif num>=13 && num<=15
    s=4;
else
    error('人数错误：超过15人');
end

bn=s*(n-1)+1;%表示偏差数量

%x=[A班工作情况，B班工作情况，偏差];
%以下b0123分别代表了四个目标中的偏差，均只考虑负偏差
%0表示当前工作数与累计安排次数之比
%1表示专班经验
%2表示平均
%3表示事故

%对于每一个班次都有条件1,2,3的负偏差，对于0的负偏差为1，因此偏差数目为3*s+5
%x(s*num+1) = b0-
%x(s*num+2) = b1a-
%x(s*num+3) = b1b- (若只有两辆班车)
%x(s*num+4) = b2a- 
%x(s*num+5) = b2b-
%x(s*num+6) = b3a-
%x(s*num+7) = b3b-

zero_num=zeros(1,num);
zero_w=zeros(1,bn);

%定义平均avg
ya=ID2(1,1:num);
yb=ID2(2,1:num);
yc=ID2(3,1:num);
yd=ID2(4,1:num);
avg=(ya+yb+yc+yd)./4;
ya_avg=ya-avg;
yb_avg=yb-avg;
yc_avg=yc-avg;
yd_avg=yd-avg;

%定义公平  
%[r_k,target_rate]=fair1(num,s,ID2,d2);
[r_k,target_rate]=fair2(num,s,ID2,d1);
    
if(s==1)
    licenseA=[ID(2,1:num),zero_w];%是否有驾照,题目必须满足无偏差,后面补零是因为后面偏差系数都是零 
    experienceA=-ID(4,1:num);
    ya_k=ya-avg;
    dangerA=ID(3,1:num);
    mina=sort(ya_avg);
    target1=mina(1)+mina(2);     

A=[-licenseA; [eye(num,num) zeros(num,bn)];[[r_k;experienceA;ya_k;dangerA] -eye(bn)]];
b=[-ones(1,1);ones(num,1);target_rate;-1;target1;0];
Aeq=[ones(1,num) zeros(1,bn)];
beq=(2);
    
elseif(s==2)
    licenseA=[ID(2,1:num),zero_num,zero_w];%后面补零是因为后面偏差系数都是零
    licenseB=[zero_num,ID(2,1:num),zero_w];%对应B班车
    experienceA=[-ID(4,1:num),zero_num];
    experienceB=[zero_num,-ID(4,1:num)];
    ya_k=[ya_avg zero_num];
    yb_k=[zero_num yb_avg];
    dangerA=[ID(3,1:num),zero_num];
    dangerB=[zero_num,ID(3,1:num)];
    mina=sort(ya_avg);
    minb=sort(yb_avg);
    target1=mina(1)+mina(2);
    target2=minb(1)+minb(2);     
     
A=[-licenseA;-licenseB; [eye(num,num) eye(num,num) zeros(num,bn)];[[r_k;experienceA;experienceB;ya_k;yb_k;dangerA;dangerB] -eye(bn)]];
b=[-ones(2,1);ones(num,1);target_rate;-1;-1;target1;target2;0;0];
Aeq=[[ones(1,num) zeros(1,num) zeros(1,bn)];[zeros(1,num) ones(1,num) zeros(1,bn)]];
beq=[2;2];

     
elseif(s==3)
    licenseA=[ID(2,1:num),zero_num,zero_num,zero_w];%后面补零是因为后面偏差系数都是零
    licenseB=[zero_num,ID(2,1:num),zero_num,zero_w];%对应B班车
    licenseC=[zero_num,zero_num,ID(2,1:num),zero_w];%后面补零是因为后面偏差系数都是零
    
    experienceA=[-ID(4,1:num),zero_num,zero_num];
    experienceB=[zero_num,-ID(4,1:num),zero_num];
    experienceC=[zero_num,zero_num,-ID(4,1:num)];
    
       ya_k=[ya_avg zero_num zero_num];
       yb_k=[zero_num yb_avg zero_num];
       yc_k=[zero_num zero_num yc_avg];
     
      dangerA=[ID(3,1:num),zero_num,zero_num];
     dangerB=[zero_num,ID(3,1:num),zero_num];
     dangerC=[zero_num,zero_num,ID(3,1:num)];
     
   mina=sort(ya_avg);
minb=sort(yb_avg);
minc=sort(yc_avg);
target1=mina(1)+mina(2);
target2=minb(1)+minb(2);
target3=minc(1)+minc(2);
          
A=[[-licenseA;-licenseB;-licenseC]; [eye(num,num) eye(num,num) eye(num,num) zeros(num,bn)];[[r_k;experienceA;experienceB;experienceC;ya_k;yb_k;yc_k;dangerA;dangerB;dangerC] -eye(bn)]];
b=[-ones(3,1);ones(num,1);target_rate;-1;-1;-1;target1;target2;target3;0;0;0];
Aeq=[[ones(1,num) zeros(1,num) zeros(1,num) zeros(1,bn)];[zeros(1,num) ones(1,num) zeros(1,num) zeros(1,bn)];[zeros(1,num) zeros(1,num) ones(1,num) zeros(1,bn)]];
beq=[2;2;2];


elseif(s==4)
    licenseA=[ID(2,1:num),zero_num,zero_num,zero_num,zero_w];%后面补零是因为后面偏差系数都是零
    licenseB=[zero_num,ID(2,1:num),zero_num,zero_num,zero_w];%对应B班车
    licenseC=[zero_num,zero_num,ID(2,1:num),zero_num,zero_w];%后面补零是因为后面偏差系数都是零
    licenseD=[zero_num,zero_num,zero_num,ID(2,1:num),zero_w];%后面补零是因为后面偏差系数都是零
    
    experienceA=[-ID(4,1:num),zero_num,zero_num,zero_num];
    experienceB=[zero_num,-ID(4,1:num),zero_num,zero_num];
    experienceC=[zero_num,zero_num,-ID(4,1:num),zero_num];
    experienceD=[zero_num,zero_num,zero_num,-ID(4,1:num)];
    
    
    ya_k=[ya_avg zero_num zero_num zero_num];
       yb_k=[zero_num yb_avg zero_num zero_num];
     yc_k=[zero_num zero_num yc_avg zero_num];
     yd_k=[zero_num zero_num  zero_num yd_avg];
     
     
     dangerA=[ID(3,1:num),zero_num,zero_num,zero_num];
     dangerB=[zero_num,ID(3,1:num),zero_num,zero_num];
     dangerC=[zero_num,zero_num,ID(3,1:num),zero_num];
     dangerD=[zero_num,zero_num,zero_num,ID(3,1:num)];
     
     
mina=sort(ya_avg);
minb=sort(yb_avg);
minc=sort(yc_avg);
mind=sort(yd_avg);
target1=mina(1)+mina(2);
target2=minb(1)+minb(2);
target3=minc(1)+minc(2);
target4=mind(1)+mind(2);
     
A=[[-licenseA;-licenseB;-licenseC;-licenseD]; [eye(num,num) eye(num,num) eye(num,num) eye(num,num) zeros(num,bn)];[[r_k;experienceA;experienceB;experienceC;experienceD;ya_k;yb_k;yc_k;yd_k;dangerA;dangerB;dangerC;dangerB;] -eye(bn)]];
b=[-ones(4,1);ones(num,1);target_rate;-1;-1;-1;-1;target1;target2;target3;target4;0;0;0;0];
Aeq=[[ones(1,num) zeros(1,num) zeros(1,num) zeros(1,num) zeros(1,bn)];[zeros(1,num) ones(1,num) zeros(1,num) zeros(1,num) zeros(1,bn)];[zeros(1,num) zeros(1,num) ones(1,num) zeros(1,num) zeros(1,bn)];[zeros(1,num) zeros(1,num)  zeros(1,num) ones(1,num) zeros(1,bn)]];
beq=[2;2;2;2];
     
else
    error('人数错误：超过15人');
end

%f为目标函数的系数矩阵
f=zeros(num*s+bn,1);

%对于每一个班次都有条件1,2,3的负偏差，因此偏差数目为3*s
%x21 = b1a-,
%x22 = b1b- 

%x23 = b2a- 
%x24 = b2b-

%x25 = b3a-
%x26 = b3b-
%s为班次


f(num*s+1)=w3;

for k=1:s
    f(num*s+k+1)=w2;
    f(num*s+s+k+1)=w1;
    f(num*s+s+s+k+1)=w0;   
end 



lb=zeros(s*num+bn,1);
ub=[ones(s*num,1) w3*ones(s*num,1)];
intcon=1:num*s;
x = intlinprog(f,intcon,A,b,Aeq,beq,lb,ub);

for k=1:N
    %添加已工作天数
    if (d1total(k)-d2total(k))>0
        d2total(k)=d2total(k)+1;
    end
end

%更新其余各信息
for k1=1:s
    for k2=1:num
        if x(k2+num*(k1-1))~=0%找到排了k1班的人序号是k2
            k3=0;
            for k=1:N  %k（对应IDtotal）为k2（对应ID）的编号
                if d1_d2total(k)>0
                    k3=k3+1;
                    if k3==k2
                        %添加专班经验
                        IDtotal(4,k)=1;            
                        %添加历史次数
                        ID2total(k1,k)=ID2total(k1,k)+1;%x(k2+num*(k1-1))
                        break
                    end
                end
            end
        end
    end
end


end