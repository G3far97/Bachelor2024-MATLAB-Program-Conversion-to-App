%Game for lung trainer
clear;close all;
cam = webcam(1);
timer=20;%practise time in seconds
Rmin=40;
Rmax=80;
%limitdiff=50;
limitmax=170;
limitbase=300;
frame=25;
timeflowerstart=0;
points=randi(360,60,30);
Nx=100;
Ny=100;
start=0;
blue=[50 86 129];
yellow=[165 116 40];
red=[124 35 35];
base=[168 176 187];
base=[212 218 250];
flower0(1:100,1:100,1:3)=0;flower0(round(Ny/2):Ny,round(0.95*Nx/2):round(1.05*Nx/2),2)=1;
%flower=flower0;flower(40:61,40:61,1)=0.5;

%calibration=input('Start Calibration');
img = snapshot(cam);[Ny,Nx,Nz]=size(img);img=img(:,round(Nx/4):round(3*Nx/4),:);[Ny,Nx,Nz]=size(img);
%load img_4.mat;
img2=double(img);
figure(1);imagesc(img);colormap(gray);
[bluemax,yellowmax,redmax]=getballs(img2,blue,red,yellow,base,limitmax,limitbase,frame,Nx,Ny,1);

calibration=input('Start Practise');
starttime=clock;
timeleft=timer;
timeleftvector=timer;
counter=1;
while timeleft>0
    img = snapshot(cam);[Ny,Nx,Nz]=size(img);img=img(:,round(Nx/4):round(3*Nx/4),:);[Ny,Nx,Nz]=size(img);
    %load img.mat;
    img2=double(img);
    figure(1);subplot(1,3,1);hold off;imagesc(img);axis equal;axis off
    [bluemax(counter),yellowmax(counter),redmax(counter)]=getballs(img2,blue,red,yellow,base,limitmax,limitbase,frame,Nx,Ny,1);
    timeleftvector(counter)=timeleft;
    subplot(1,3,2);plot(timeleftvector,bluemax,'b.-',timeleftvector,yellowmax,'y.-',timeleftvector,redmax,'r.-');
    axis([0,timer,0,Ny]);
    %saveas(1,['test',num2str(counter),'.jpg'],'jpg');
    counter=counter+1;
    currenttime=clock;
    time=dot(currenttime-starttime,[0;0;3600*25;3600;60;1]);
    timeleft=timer-time;
    kblue=find(bluemax>Ny/2);kyellow=find(yellowmax>Ny/2);kred=find(redmax>Ny/2);
    subplot(1,3,3);hold off;plot(1,length(kblue),'bo','MarkerFaceColor', 'b');hold on;
    plot(2,length(kyellow),'yo','MarkerFaceColor','y');
    plot(3,length(kred),'ro','MarkerFaceColor','r');axis([0,4,0,100]);
%     if start==0 && pos(1)>pos0(1)+10
%         timeflowerstart=time;
%         start=1;
%     end
%     timeflower=time-timeflowerstart;
%     if pos(1)<pos0(1)+11
%         start=0;
%         timeflowerstart=0;
%         timeflower=0;
%     end
    
%     flower=flower0;
%     for j=1:floor(timeflower)
%             xpoints=round(Nx/2+(timeflower+5-j)*cosd(points(j,:)));
%             ypoints=round(Nx/2+(timeflower+5-j)*sind(points(j,:)));
%             for i=1:length(xpoints)
%                 flower(ypoints(i),xpoints(i),1)=(time-5+j)/5;
%                 flower(ypoints(i),xpoints(i),2)=(time-5+j)/10+0.1;
%                 flower(ypoints(i),xpoints(i),3)=1;
%             end
%     end
%     subplot(1,2,1);imshow(img);subplot(1,2,2);imagesc(flower);axis equal;axis tight;pause(0.0001);
    
    
end

kb=round(100*length(find(bluemax>max(0,min(bluemax))+0.5*(max(bluemax)-max(0,min(bluemax)))))/length(bluemax));
ky=round(100*length(find(yellowmax>max(0,min(yellowmax))+0.5*(max(yellowmax)-max(0,min(yellowmax)))))/length(yellowmax));
kr=round(100*length(find(redmax>max(0,min(redmax))+0.5*(max(redmax)-max(0,min(redmax)))))/length(redmax));
subplot(1,3,2);
text(0.1,10,'blue: ','color','b');text(0.3*timer,10,[num2str(kb),' %'],'color','b');
text(0.1,40,'yellow: ','color','k');text(0.3*timer,40,[num2str(ky),' %'],'color','k');
text(0.1,70,'red: ','color','r');text(0.3*timer,70,[num2str(kr),' %'],'color','r');
title(['Total: ',num2str(kr+kb+ky),'Points']);
axis off;

function [bluemax,yellowmax,redmax]=getballs(img2,blue,red,yellow,base,limitmax,limitbase,frame,Nx,Ny,p)
[kyblue1,kxblue1]=find((img2(:,:,1)-blue(1)).^2+(img2(:,:,2)-blue(2)).^2+(img2(:,:,3)-blue(3)).^2<limitmax);
[kyblue,kxblue]=find((img2(max(1,min(kyblue1)-frame):min(Ny,max(kyblue1)+frame),max(1,min(kxblue1)-frame):min(Nx,max(kxblue1)+frame),1)-blue(1)).^2+(img2(max(1,min(kyblue1)-frame):min(Ny,max(kyblue1)+frame),max(1,min(kxblue1)-frame):min(Nx,max(kxblue1)+frame),2)-blue(2)).^2+(img2(max(1,min(kyblue1)-frame):min(Ny,max(kyblue1)+frame),max(1,min(kxblue1)-frame):min(Nx,max(kxblue1)+frame),3)-blue(3)).^2<2*limitmax);
kyblue=kyblue+min(kyblue1)-frame-1;kxblue=kxblue+min(kxblue1)-frame-1;

[kyyellow1,kxyellow1]=find((img2(:,:,1)-yellow(1)).^2+(img2(:,:,2)-yellow(2)).^2+(img2(:,:,3)-yellow(3)).^2<limitmax);
[kyyellow,kxyellow]=find((img2(max(1,min(kyyellow1)-frame):min(Ny,max(kyyellow1)+frame),max(1,min(kxyellow1)-frame):min(Nx,max(kxyellow1)+frame),1)-yellow(1)).^2+(img2(max(1,min(kyyellow1)-frame):min(Ny,max(kyyellow1)+frame),max(1,min(kxyellow1)-frame):min(Nx,max(kxyellow1)+frame),2)-yellow(2)).^2+(img2(max(1,min(kyyellow1)-frame):min(Ny,max(kyyellow1)+frame),max(1,min(kxyellow1)-frame):min(Nx,max(kxyellow1)+frame),3)-yellow(3)).^2<2*limitmax);
kyyellow=kyyellow+min(kyyellow1)-frame-1;kxyellow=kxyellow+min(kxyellow1)-frame-1;

[kyred1,kxred1]=find((img2(:,:,1)-red(1)).^2+(img2(:,:,2)-red(2)).^2+(img2(:,:,3)-red(3)).^2<limitmax);
[kyred,kxred]=find((img2(max(1,min(kyred1)-frame):min(Ny,max(kyred1)+frame),max(1,min(kxred1)-frame):min(Nx,max(kxred1)+frame),1)-red(1)).^2+(img2(max(1,min(kyred1)-frame):min(Ny,max(kyred1)+frame),max(1,min(kxred1)-frame):min(Nx,max(kxred1)+frame),2)-red(2)).^2+(img2(max(1,min(kyred1)-frame):min(Ny,max(kyred1)+frame),max(1,min(kxred1)-frame):min(Nx,max(kxred1)+frame),3)-red(3)).^2<2*limitmax);
kyred=kyred+min(kyred1)-frame-1;kxred=kxred+min(kxred1)-frame-1;

xmin=min(min(min(kxblue),min(kxyellow)),min(kxred));
xmax=max(max(max(kxblue),max(kxyellow)),max(kxred));
ymin=max(max(max(kyblue),max(kyyellow)),max(kyred));
[kybase1,kxbase1]=find((img2(ymin:Ny,xmin:xmax,1)-base(1)).^2+(img2(ymin:Ny,xmin:xmax,2)-base(2)).^2+(img2(ymin:Ny,xmin:xmax,3)-base(3)).^2<limitbase);
kybase1=kybase1+ymin;kxbase1=kxbase1+xmin;
k=find(abs(kybase1-mean(kybase1))<10);
kybase=kybase1(k);kxbase=kxbase1(k);

if isempty(kybase)==0
    basemax=min(kybase);
else
    basemax=Ny;
end
if isempty(kyblue)==0
    bluemax=basemax-min(kyblue);
else
    bluemax=0;
end
if isempty(kyyellow)==0
    yellowmax=basemax-min(kyyellow);
else
    yellowmax=0;
end
if isempty(kyred)==0
    redmax=basemax-min(kyred);
else
    redmax=0;
end

%pos=[bluemax yellowmax redmax];
if p==1
    hold on;plot(kxblue,kyblue,'b.');plot(kxyellow,kyyellow,'y.');plot(kxred,kyred,'r.');plot(kxbase,kybase,'g.');
    %title(['Ball found: ',num2str(bluemax),' ',num2str(yellowmax),' ',num2str(redmax),' ',num2str(basemax)])
end
end