Ys = Yf/2;
Yaux  = (1/2)*(1+gammar)*(Vm^2/Am);
Ys = 

%% Plot S-Curve Zone#1 t0 - t1
for t = 1 : 100
    %s(t) = v0*t + (jm*t^3)/6;    
    v(t) = v0 + (jm*t^2)/2;
    %a(t) = jm*t;
end

%% Plot S-Curve Zone#2 t1 - t2
for t = 101 : 200
        vh = (vs +v0)/2;
        %s(t) = vh*t + (as*t^2)/2 + (jm*t^3)/6;
        v(t) = v(100) + as*t + (jm*t^2)/2;
        %a(t) = as + jm*t;
end

%%
t = 1 : 100;
plot(t,v(t),'-*')
xlabel('Time (Second)')
ylabel('Velocity')
title('Plot of the S-Curve Velocity VS TIme')