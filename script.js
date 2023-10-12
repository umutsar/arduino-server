
const socket = new WebSocket('ws://192.168.43.73:8766');
const analog_data = document.getElementById('analog_data');

socket.addEventListener(
    'open', (event) => {
        console.log('WebSocket bağlantısı başarıyla kuruldu.');
    });

socket.addEventListener(
    'message', (event) => {
        const data = event.data;
            console.log(`Arduino'dan gelen veri: ${data}`);
            analog_data.innerText = `Potansiyometre değeri: ${data}`
    });

socket.addEventListener(
    'close', (event) => {
        console.log('WebSocket bağlantısı kapandı.');
    });

socket.addEventListener(
    'error', (event) => {
        console.error('WebSocket hatası:', event);
    });
