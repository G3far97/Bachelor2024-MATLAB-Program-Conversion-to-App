clear;close all;
load img_4.mat;
img2=double(img);
figure(1);
BW = edge((img2(:,:,1)+img2(:,:,2)+img2(:,:,3))/3,'canny');
BW = edge(img2(:,:,1),'canny',0.2);
subplot(2,2,1);imshow(BW);

[H,theta,rho] = hough(BW);

subplot(2,2,2);imshow(imadjust(rescale(H)),[],...
       'XData',theta,...
       'YData',rho,...
       'InitialMagnification','fit');
xlabel('\theta (degrees)')
ylabel('\rho')
axis on
axis normal 
hold on
colormap(gca,hot)

P = houghpeaks(H,15,'threshold',ceil(0.5*max(H(:))));
k=find(abs(P(:,2)-90)<5);
Pnew(:,1)=P(k,1);
Pnew(:,2)=P(k,2);
P=Pnew;
x = theta(P(:,2));
y = rho(P(:,1));
plot(x,y,'s','color','g','Linewidth',2);

lines = houghlines(BW,theta,rho,P,'FillGap',5,'MinLength',7);

subplot(2,2,3);imagesc(img);hold on
max_len = 0;
for k = 1:length(lines)
   xy = [lines(k).point1; lines(k).point2];
   plot(xy(:,1),xy(:,2),'LineWidth',2,'Color','green');

   % Plot beginnings and ends of lines
   plot(xy(1,1),xy(1,2),'x','LineWidth',2,'Color','yellow');
   plot(xy(2,1),xy(2,2),'x','LineWidth',2,'Color','red');

   % Determine the endpoints of the longest line segment
   len = norm(lines(k).point1 - lines(k).point2);
   if ( len > max_len)
      max_len = len;
      xy_long = xy;
   end
end
% highlight the longest line segment
plot(xy_long(:,1),xy_long(:,2),'LineWidth',2,'Color','red');