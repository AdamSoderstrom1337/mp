m = 2;      % Massa
h = 0.02;   % Steglängd
g = 9.81; 
k = 20;     % Fjäderkonstant
d = 0.4;    % Dämpningskoefficient

% Antal sampelvärden
N = 2000;

% Antal massor
M = 2;

% Initial värden
x(1,1) = -1;
x(1,2) = 0;
v(1,1) = 0;
v(1,2) = 0;

for n=2:N
        % Beräkna kraft för varje massa
         F1 = k*((x(n-1,2)-x(n-1,1))-10)+d*(v(n-1,2)-v(n-1,1));
         F2 = k*((x(n-1,1)-x(n-1,2))+10)+d*(v(n-1,1)-v(n-1,2));
         
        %Uppdatera position och hastighet
        v(n,1) = v(n-1,1) + F1*h/m;
        x(n,1) = x(n-1,1) + v(n,1)*h;
        v(n,2) = v(n-1,2) + F2*h/m;
        x(n,2) = x(n-1,2) + v(n,2)*h;
        
  end
figure(1)
plot(x);
title('Två massor r');
ylabel('Position');
