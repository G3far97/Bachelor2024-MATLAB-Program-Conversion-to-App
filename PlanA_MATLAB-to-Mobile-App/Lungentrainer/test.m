close all;clear;

load img.mat;

figure(1);subplot(2,2,1);imagesc(img);

img2=double(img);

img_red=img2(:,:,1)-img2(:,:,2)-img2(:,:,3);img_red=img_red-min(min(img_red));

img_blue=img2(:,:,3)-img2(:,:,1)-img2(:,:,2);img_blue=img_blue-min(min(img_blue));

img3=rgb2ycbcr(img2);

[ky,kx]=find(abs(img3(:,:,2)+45)<3);min(ky)

length(ky)

hold on;plot(kx,ky,'y.');

[ky,kx]=find(img_blue>0.9*max(max(img_blue)));min(ky)

length(ky)

hold on;plot(kx,ky,'b.');

[ky,kx]=find(img_red>0.95*max(max(img_red)));min(ky)

length(ky)

hold on;plot(kx,ky,'r.');