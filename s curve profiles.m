% S-Curve Motion Control
% M5842445 Sarayut Pongsanthia

y = zeros(1,100); y1 = zeros(1,100); y2 = zeros(1,100);
% SIGMF(X, [A, C]) = 1./(1 + EXP(-A*(X-C))

% define variable
  
t = 5;                  % t = time second
a1=7; a2=7;             % a = slope
c1=0.8; c2 =4.2;        % c = half_point
x = linspace(0,t,500); % amout of point for plot
for i = 1:length(x)
    y1(i) = 1/(1 + exp(-a1*(x(i)-c1)));     % S-curve acceleration 
    y2(i) = 1/(1 + exp(-a2*(x(i)-c2)));     % S-curve deceleration
    y(i)  = abs(y1(i)-y2(i))*255;  % absolute and *255 for scale to PWM
    %y = abs(sigmf(x, params(1:2)) - sigmf(x, params(3:4)));
end

plot(x,y,'--r*')
xlabel('Time (Seconds)')
ylabel('PWM Max.255')
