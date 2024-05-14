function main_entry_point

    % Load pre-captured image
    imageData = coder.load('img.mat');

    % Convert image data to double
    imageData = double(imageData.img);

    % Call lung_trainer_game function with pre-captured image data
    Lungentrainer02(imageData);

end