% Name : Vipul Jain    Roll.No : 180869
m=100;
dz=0.01;
n=101;
dt=0.1*(dz^2);
T=1/dt;

mxerror=10^-8;
error=1;
d=zeros(1,n);
b=zeros(1,n);
a=zeros(1,n);
c=zeros(1,n);
theta_old=zeros(1,n);

theta_new=theta_old;
theta_zero = theta_old;
theta_mid = theta_old;
itr=0;
while(error>mxerror)
    itr=itr+1; 
    %applying bc
    d(1)=1; d(n)=0;
    c(1)=0; c(n)=0;
    b(1)=1; b(n)=3;
    a(1)=0; a(n)=-4; 
    alpha=1;
    
    for i=2:n-1
        a(i)=-dt*(1/(dz^2) - 1/(2*dz*((i-1)*dz-1)));
        b(i)=-dt*(m/((i-1)*dz - 1) - 2/(dz^2) - T);
        c(i)=-dt*(1/(dz^2) + 1/(2*dz*((i-1)*dz-1)));
        d(i)=theta_old(i);
    end
    
    b(n)=b(n)-(alpha/a(n-1))*c(n-1);
    a(n)=a(n)-(alpha/a(n-1))*b(n-1);
    d(n)=d(n)-(alpha/a(n-1))*d(n-1);
    theta_new=Thomas(b,a,c,d,n);
    error=sqrt(sum((theta_new-theta_old).^2));
    theta_old=theta_new;
    if(itr==5) 
        theta_zero = theta_old;
    end
    if(itr==500)
        theta_mid = theta_old;
    end
end

z=linspace(0,1,n);
x = steadystate();
plot(z,theta_new,z,theta_zero,z,theta_mid,z,x,'o');
title('\theta vs z')
legend({'Steady State,time \tau = \infty','Transient near \tau = 0','Transient at \tau = 0.005','Steady State Solver'})
xlabel('z')
ylabel('\theta')




function [theta]=Thomas(b,a,c,d,n)  
    for i=2:n
     r=a(i)/b(i-1);
     b(i)=b(i)-r*c(i-1);
     d(i)=d(i)-r*d(i-1);
    end

    theta=zeros(1,n);
    theta(n)=d(n)/b(n);
    for i=n-1:-1:1
      theta(i)=(d(i)-(theta(i+1)*c(i)))/b(i);
    end
end


function [x] = steadystate()
    m=100;
    dz=0.01;
    dt=0.1*(dz^2);
    T=1/dt;
    n=101;
    d=zeros(1,n);
    b=zeros(1,n);
    a=zeros(1,n);
    c=zeros(1,n);
    x = zeros(1,n);
    d(1)=1; d(n)=0;
    c(1)=0; c(n)=0;
    b(1)=1; b(n)=3;
    a(1)=0; a(n)=-4; 
    alpha=1;
    
    for i=2:n-1
        a(i)=(1/(dz^2) - 1/(2*dz*((i-1)*dz-1)));
        b(i)=(m/((i-1)*dz - 1) - 2/(dz^2));
        c(i)=(1/(dz^2) + 1/(2*dz*((i-1)*dz-1)));
    end
    
    b(n)=b(n)-(alpha/a(n-1))*c(n-1);
    a(n)=a(n)-(alpha/a(n-1))*b(n-1);
    d(n)=d(n)-(alpha/a(n-1))*d(n-1);
    
    for i = 2:n
        b(i) = b(i) - c(i-1)*(a(i)/b(i-1));
        d(i) = d(i) - d(i-1)*(a(i)/b(i-1));
    end
    x(n)=d(n)/b(n);
    for i = n-1:-1:1
        x(i)=(d(i)-(c(i)*x(i+1)))/b(i);
    end
end
