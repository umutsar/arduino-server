import serial
import asyncio
import websockets

ser = serial.Serial('COM3', 9600)

async def server(websocket, path):
    try:
        while True:
            data = ser.readline().decode('utf-8').strip()
            await websocket.send(data)
    except websockets.exceptions.ConnectionClosed:
        pass

start_server = websockets.serve(server, "127.0.0.1", 8766)

asyncio.get_event_loop().run_until_complete(start_server)
asyncio.get_event_loop().run_forever()
