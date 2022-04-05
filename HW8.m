% Name : Vipul Jain    Roll.No : 180869
h=0.25;beta=1.66;gamma=beta/3.65;
n=121;
u=zeros(2,n);
u(2,1) = 1/763;u(1,1) = 1- u(2,1);
for i = 1:n-1
    dy = delta(u,i,beta,gamma,h);
    u(:,i+1) = u(:,i) + dy;
end
S = u(1,:); I = u(2,:);
R = 1.- u(1,:)-u(2,:);
t= linspace(0,n-1,n);
plot(t/4,S,t/4,I,t/4,R,'g-')
legend({'S','I','R'})
title('S,I,R vs time(days)')
xlabel('Days')
ylabel('S-I-R')
I_max = max(I)
tn = find(abs(u(2,:)-0.003713) < 0.0001);
yn = u(2,tn);
ans = tn/4
%%
function dy = delta(u,i,beta,gamma,h)
    dy = zeros(2);
    k = zeros(2,4);
    for j = 1:2
        k(j,1) = f(j,u(1,i),u(2,i),beta,gamma);
    end
    for j = 1:2
        k(j,2) = f(j,u(1,i)+(h*k(1,1))/2,u(2,i)+(h*k(2,1))/2,beta,gamma);
    end
    for j = 1:2
        k(j,3) = f(j,u(1,i)+(h*k(1,2))/2,u(2,i)+(h*k(2,2))/2,beta,gamma);
    end
    for j = 1:2
        k(j,4) = f(j,u(1,i)+(h*k(1,3)),u(2,i)+(h*k(2,3)),beta,gamma);
    end
    
    dy = (h/6).*(k(:,1)+ 2.*k(:,2)+ 2.*k(:,3)+ k(:,4));
end

function k = f(j,u1,u2,beta,gamma)
    if(j==1)
        k = -beta*u1*u2;
    end
    if(j==2)
        k = beta*u1*u2 - gamma*u2;
    end
end