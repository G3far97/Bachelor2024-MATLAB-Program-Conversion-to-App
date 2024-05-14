%Game for lung trainer
clear;close all;
cam = webcam(1);
timer=20;%practise time in seconds
Rmin=40;
Rmax=80;
%limitdiff=50;
limitmax=170;
frame=25;
timeflowerstart=0;
points=randi(360,60,30);
Nx=100;
Ny=100;
start=0;
blue=[50 86 129];
yellow=[165 116 40];
red=[124 35 35];
flower0(1:100,1:100,1:3)=0;flower0(round(Ny/2):Ny,round(0.95*Nx/2):round(1.05*Nx/2),2)=1;
%flower=flower0;flower(40:61,40:61,1)=0.5;

%calibration=input('Start Calibration');
img = snapshot(cam);[Ny,Nx,Nz]=size(img);img=img(:,round(Nx/4):round(3*Nx/4),:);[Ny,Nx,Nz]=size(img);
%load img_4.mat;
img2=double(img);

figure(1);imagesc(img);colormap(gray);
[bluemax,yellowmax,redmax]=getballs(img2,blue,red,yellow,limitmax,frame,Nx,Ny,1);

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
    [bluemax(counter),yellowmax(counter),redmax(counter)]=getballs(img2,blue,red,yellow,limitmax,frame,Nx,Ny,1);
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
    plot(2,length(kyellow),'ko','MarkerFaceColor','y');
    plot(3,length(kred),'ro','MarkerFaceColor','r');axis([0,4,0,100]);axis off;
end

kb=round(100*length(find(bluemax>max(0,min(bluemax))+0.5*(max(bluemax)-max(0,min(bluemax)))))/length(bluemax));
ky=round(100*length(find(yellowmax>max(0,min(yellowmax))+0.5*(max(yellowmax)-max(0,min(yellowmax)))))/length(yellowmax));
kr=round(100*length(find(redmax>max(0,min(redmax))+0.5*(max(redmax)-max(0,min(redmax)))))/length(redmax));
subplot(1,3,2);
text(0.1,10,'blue: ','color','b');text(0.4*timer,10,[num2str(kb),' %'],'color','b');
text(0.1,40,'yellow: ','color','k');text(0.4*timer,40,[num2str(ky),' %'],'color','k');
text(0.1,70,'red: ','color','r');text(0.4*timer,70,[num2str(kr),' %'],'color','r');
title(['Total: ',num2str(kr+kb+ky),'Points']);
axis off;

function [bluemax,yellowmax,redmax]=getballs(img2,blue,red,yellow,limitmax,frame,Nx,Ny,p)
[kyblue1,kxblue1]=find((img2(:,:,1)-blue(1)).^2+(img2(:,:,2)-blue(2)).^2+(img2(:,:,3)-blue(3)).^2<limitmax);
[kyblue,kxblue]=find((img2(max(1,min(kyblue1)-frame):min(Ny,max(kyblue1)+frame),max(1,min(kxblue1)-frame):min(Nx,max(kxblue1)+frame),1)-blue(1)).^2+(img2(max(1,min(kyblue1)-frame):min(Ny,max(kyblue1)+frame),max(1,min(kxblue1)-frame):min(Nx,max(kxblue1)+frame),2)-blue(2)).^2+(img2(max(1,min(kyblue1)-frame):min(Ny,max(kyblue1)+frame),max(1,min(kxblue1)-frame):min(Nx,max(kxblue1)+frame),3)-blue(3)).^2<2*limitmax);
kyblue=kyblue+min(kyblue1)-frame-1;kxblue=kxblue+min(kxblue1)-frame-1;

[kyyellow1,kxyellow1]=find((img2(:,:,1)-yellow(1)).^2+(img2(:,:,2)-yellow(2)).^2+(img2(:,:,3)-yellow(3)).^2<limitmax);
[kyyellow,kxyellow]=find((img2(max(1,min(kyyellow1)-frame):min(Ny,max(kyyellow1)+frame),max(1,min(kxyellow1)-frame):min(Nx,max(kxyellow1)+frame),1)-yellow(1)).^2+(img2(max(1,min(kyyellow1)-frame):min(Ny,max(kyyellow1)+frame),max(1,min(kxyellow1)-frame):min(Nx,max(kxyellow1)+frame),2)-yellow(2)).^2+(img2(max(1,min(kyyellow1)-frame):min(Ny,max(kyyellow1)+frame),max(1,min(kxyellow1)-frame):min(Nx,max(kxyellow1)+frame),3)-yellow(3)).^2<2*limitmax);
kyyellow=kyyellow+min(kyyellow1)-frame-1;kxyellow=kxyellow+min(kxyellow1)-frame-1;

[kyred1,kxred1]=find((img2(:,:,1)-red(1)).^2+(img2(:,:,2)-red(2)).^2+(img2(:,:,3)-red(3)).^2<limitmax);
[kyred,kxred]=find((img2(max(1,min(kyred1)-frame):min(Ny,max(kyred1)+frame),max(1,min(kxred1)-frame):min(Nx,max(kxred1)+frame),1)-red(1)).^2+(img2(max(1,min(kyred1)-frame):min(Ny,max(kyred1)+frame),max(1,min(kxred1)-frame):min(Nx,max(kxred1)+frame),2)-red(2)).^2+(img2(max(1,min(kyred1)-frame):min(Ny,max(kyred1)+frame),max(1,min(kxred1)-frame):min(Nx,max(kxred1)+frame),3)-red(3)).^2<2*limitmax);
kyred=kyred+min(kyred1)-frame-1;kxred=kxred+min(kxred1)-frame-1;

bluemax=Ny-min(kyblue)+1;yellowmax=Ny-min(kyyellow)+1;redmax=Ny-min(kyred)+1;
if p==1
    hold on;plot(kxblue,kyblue,'b.');plot(kxyellow,kyyellow,'y.');plot(kxred,kyred,'r.');
    %title(['Ball found: ',num2str(bluemax),' ',num2str(yellowmax),' ',num2str(redmax),' ',num2str(basemax)])
end
end