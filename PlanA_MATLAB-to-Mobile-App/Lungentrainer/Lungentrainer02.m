function Lungentrainer02(imageData)
    
    % Set parameters
    
    timer = 20; % Practise time in seconds
    
    %Rmin = 40;
    %Rmax = 80;
    
    limitmax = 170;
    frame = 25;
    
    Nx = 100;
    Ny = 100;
    
    blue = [50 86 129];
    yellow = [165 116 40];
    red = [124 35 35];

    % Use the provided image data
    img = imageData;

    % Display initial image
    
    figure(1);
    imagesc(img);
    colormap(gray);

    % Get initial ball positions
    [bluemax, yellowmax, redmax] = getballs( ...
        img, blue, red, yellow, limitmax, frame, Nx, Ny, 1);

    % Start practise
    %calibration = input('Start Practise: Press any key to start');

    % Initialize variables for time tracking
    
    starttime = datetime("now");
    timeleft = timer;
    timeleftvector = timer;
    
    counter = 1;

    % Main loop
    while timeleft > 0 && counter <= length(timeleftvector)
        
        % Process image
        
        subplot(1, 3, 1);
        imagesc(img);
        axis equal;
        axis off;
        
        [bluemax(counter), yellowmax(counter), redmax(counter)] = ...
        getballs( img, blue, red, yellow, limitmax, frame, Nx, Ny, 1);

        % Update time
        
        timeleftvector(counter) = timeleft;
        subplot(1, 3, 2);
        
        plot(timeleftvector(1:counter), bluemax(1:counter), ...
            'b.-', timeleftvector(1:counter), yellowmax(1:counter), ...
            'y.-', timeleftvector(1:counter), redmax(1:counter), 'r.-');
        
        axis([0, timer, 0, Ny]);
        counter = counter + 1;
        
        currenttime = datetime("now");
        time = seconds(currenttime - starttime);
        timeleft = timer - time;

        % Plot ball counts
        
        kblue = find(bluemax > Ny / 2);
        kyellow = find(yellowmax > Ny / 2);
        kred = find(redmax > Ny / 2);
        
        subplot(1, 3, 3);
        hold off;
        
        plot(1, length(kblue), 'bo', 'MarkerFaceColor', 'b');
        hold on;
        
        plot(2, length(kyellow), 'ko', 'MarkerFaceColor', 'y');
        
        plot(3, length(kred), 'ro', 'MarkerFaceColor', 'r');
        
        axis([0, 4, 0, 100]);
        axis off;
    
    end

    % Calculate percentages
    
    kb = round(100 * length(find(bluemax > max(0, min(bluemax)) + ...
        0.5 * (max(bluemax) - ...
        max(0, min(bluemax))))) / length(bluemax));
    
    ky = round(100 * length(find( ...
        yellowmax > max(0, min(yellowmax)) + ...
        0.5 * (max(yellowmax) - ...
        max(0, min(yellowmax))))) / length(yellowmax));
    
    kr = round(100 * length(find(redmax > max(0, min(redmax)) + ...
        0.5 * (max(redmax) - max(0, min(redmax))))) / length(redmax));

    % Display results
    
    subplot(1, 3, 2);
    
    text(0.1, 10, 'blue: ', 'color', 'b');
    text(0.4 * timer, 10, ...
        sprintf('%d %%', int32(round(kb))), 'color', 'b');
    
    text(0.1, 40, 'yellow: ', 'color', 'k');
    text(0.4 * timer, 40, ...
        sprintf('%d %%', int32(round(ky))), 'color', 'k');
    
    text(0.1, 70, 'red: ', 'color', 'r');
    text(0.4 * timer, 70, ...
        sprintf('%d %%', int32(round(kr))), 'color', 'r');
    
    title(['Total: ', sprintf('%d', int32(kr + kb + ky)), ' Points']);
    axis off;

end

function [bluemax, yellowmax, redmax] = getballs( ...
    img2, blue, red, yellow, limitmax, frame, Nx, Ny, p)
    
    % Ball detection function
    
    [kyblue1, kxblue1] = find((img2(:, :, 1) - blue(1)).^2 + ...
        (img2(:, :, 2) - blue(2)).^2 + ...
        (img2(:, :, 3) - blue(3)).^2 < limitmax);
    
    [kyblue, kxblue] = find((img2(max(1, min(kyblue1) - frame): ...
        min(Ny, max(kyblue1) + frame), max(1, min(kxblue1) - frame): ...
        min(Nx, max(kxblue1) + frame), 1) - blue(1)).^2 + ...
        (img2(max(1, min(kyblue1) - frame): ...
        min(Ny, max(kyblue1) + frame), max(1, min(kxblue1) - frame): ...
        min(Nx, max(kxblue1) + frame), 2) - blue(2)).^2 + ...
        (img2(max(1, min(kyblue1) - frame): ...
        min(Ny, max(kyblue1) + frame), max(1, min(kxblue1) - frame): ...
        min(Nx, max(kxblue1) + frame), 3) - ...
        blue(3)).^2 < 2 * limitmax);
    
    kyblue = kyblue + min(kyblue1) - frame - 1;
    kxblue = kxblue + min(kxblue1) - frame - 1;

    [kyyellow1, kxyellow1] = find((img2(:, :, 1) - yellow(1)).^2 + ...
        (img2(:, :, 2) - yellow(2)).^2 + (img2(:, :, 3) - ...
        yellow(3)).^2 < limitmax);
    
    [kyyellow, kxyellow] = find( ...
        (img2(max(1, min(kyyellow1) - frame): ...
        min(Ny, max(kyyellow1) + frame), ...
        max(1, min(kxyellow1) - frame): ...
        min(Nx, max(kxyellow1) + frame), 1) - ...
        yellow(1)).^2 + (img2(max(1, min(kyyellow1) - frame): ...
        min(Ny, max(kyyellow1) + frame), ...
        max(1, min(kxyellow1) - frame): ...
        min(Nx, max(kxyellow1) + frame), 2) - yellow(2)).^2 + ...
        (img2(max(1, min(kyyellow1) - frame): ...
        min(Ny, max(kyyellow1) + frame), ...
        max(1, min(kxyellow1) - frame): ...
        min(Nx, max(kxyellow1) + frame), 3) - ...
        yellow(3)).^2 < 2 * limitmax);
    
    kyyellow = kyyellow + min(kyyellow1) - frame - 1;
    kxyellow = kxyellow + min(kxyellow1) - frame - 1;

    [kyred1, kxred1] = find((img2(:, :, 1) - red(1)).^2 + ...
        (img2(:, :, 2) - red(2)).^2 + ...
        (img2(:, :, 3) - red(3)).^2 < limitmax);
    
    [kyred, kxred] = find((img2(max(1, min(kyred1) - frame): ...
        min(Ny, max(kyred1) + frame), max(1, min(kxred1) - frame): ...
        min(Nx, max(kxred1) + frame), 1) - red(1)).^2 + ...
        (img2(max(1, min(kyred1) - frame): ...
        min(Ny, max(kyred1) + frame), max(1, min(kxred1) - frame): ...
        min(Nx, max(kxred1) + frame), 2) - red(2)).^2 + ...
        (img2(max(1, min(kyred1) - frame): ...
        min(Ny, max(kyred1) + frame), max(1, min(kxred1) - frame): ...
        min(Nx, max(kxred1) + frame), 3) - red(3)).^2 < 2 * limitmax);
    
    kyred = kyred + min(kyred1) - frame - 1;
    kxred = kxred + min(kxred1) - frame - 1;

    if ~isempty(kyblue)
        bluemax = Ny - min(kyblue) + 1;
    else
        % Handle the case when kyblue is empty 
        % (e.g., set bluemax to some default value)
        bluemax = 0; % or any other appropriate default value
    end

    if ~isempty(kyyellow)
        yellowmax = Ny - min(kyyellow) + 1;
    else
        % Handle the case when kyyellow is empty 
        % (e.g., set yellowmax to some default value)
        yellowmax = 0; % or any other appropriate default value
    end

    if ~isempty(kyred)
        redmax = Ny - min(kyred) + 1;
    else
        % Handle the case when kyred is empty 
        % (e.g., set redmax to some default value)
        redmax = 0; % or any other appropriate default value
    end

    if p == 1
        hold on;
        plot(kxblue, kyblue, 'b.');
        plot(kxyellow, kyyellow, 'y.');
        plot(kxred, kyred, 'r.');
    end
    
end