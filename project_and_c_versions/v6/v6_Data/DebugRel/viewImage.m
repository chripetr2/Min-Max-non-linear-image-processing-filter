clear all
close all
clc


%DEFINE THE SIZE OF THE IMAGE
rows=144;
cols=176;

% OPEN AND READ THE IMAGE FILE
fid=fopen('akiyo0_r.y','rb'); 

        A = fread(fid,[cols,rows]);
       
fclose(fid);

B=A'

% PREVIEW THE FILE
cmap = contrast(B);

colormap(cmap)
figure(3);
imagesc(B)






    

