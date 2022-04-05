% Name : Vipul Jain    Roll.No : 180869
m=50;dx=0.01;
n=101;
a = ones(n,1);
b = ones(n,1).*(-2-(m*m*dx*dx));
c = ones(n,1);
d = zeros(n,1);
x = zeros(n,1);
a(1)=0;a(n)=-4;
b(1)=1;b(n)=3;
c(1)=0;c(n)=0;
d(1)=1;

alpha=1; 

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
t= linspace(0,n-1,n);
z = linspace(0,1,10*n-9);
y = sinh(m-(m*z))/sinh(m);
plot(t/100,x,'--o',z,y);
legend({'? (numerical solution)','?a (analytical solution)'})
title('? and ?a vs. x')
xlabel('x')
ylabel('? and ?a')