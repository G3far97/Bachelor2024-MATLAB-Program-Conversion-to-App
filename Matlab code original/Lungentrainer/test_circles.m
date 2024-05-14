clear;close all;
load img_4.mat;
img2=double(img);
figure(1);
imshow(img);

[centers rr] = imfindcircles(img(:,:,1),[40 80],'sensitivity',0.97)
viscircles(centers,rr)