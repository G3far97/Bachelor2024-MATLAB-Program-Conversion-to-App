document.addEventListener('DOMContentLoaded', () => {
    const video = document.getElementById('video');
    const startButton = document.getElementById('start');
    const countdownDisplay = document.getElementById('countdown');
    const usersDropdown = document.getElementById('users');
    const newUserInput = document.getElementById('newUser');
    const addUserButton = document.getElementById('addUser');
    const roundsDropdown = document.getElementById('rounds');
    const timeDropdown = document.getElementById('time');

    // Access the user's camera
    navigator.mediaDevices.getUserMedia({ video: true })
        .then(stream => {
            video.srcObject = stream;
        })
        .catch(error => {
            console.error('Error accessing the camera', error);
        });

    startButton.addEventListener('click', () => {
        const time = parseInt(timeDropdown.value, 10);
        startCountdown(time);
    });

    addUserButton.addEventListener('click', () => {
        const newUser = newUserInput.value.trim();
        if (newUser) {
            const newOption = document.createElement('option');
            newOption.value = newUser;
            newOption.textContent = newUser;
            usersDropdown.appendChild(newOption);
            newUserInput.value = '';
        }
    });

    function startCountdown(time) {
        let countdown = time;
        countdownDisplay.textContent = countdown;
        const interval = setInterval(() => {
            countdown -= 1;
            countdownDisplay.textContent = countdown;
            if (countdown <= 0) {
                clearInterval(interval);
                countdownDisplay.textContent = '';
            }
        }, 1000);
    }
});
