from fastapi import APIRouter, WebSocket, WebSocketDisconnect
from fastapi.responses import HTMLResponse
import asyncio
from datetime import datetime
import json
import random
from core.sensors.temperature_sensor import TemperatureSensor as ts
from core.tools.geolocalization import get_actual_position
router = APIRouter()

# Almacenar las conexiones WebSocket activas
websocket_connections = []

# Página HTML de prueba para conectar a WebSocket
html_content = """
<!DOCTYPE html>
<html>
    <head>
        <title>WebSocket Test</title>
    </head>
    <body>
        <h1>WebSocket Test</h1>
        <button onclick="connectWebSocket()">Connect WebSocket</button>
        <div id="message"></div>
<script>
    let socket;

    function connectWebSocket() {
        socket = new WebSocket("ws://localhost:8082/ws");
        socket.onmessage = function(event) {
            document.getElementById("message").textContent = "Server Time: " + event.data;
        };
    }
</script>
    </body>
</html>
"""

@router.websocket("/ws")
async def websocket_endpoint(websocket: WebSocket):
    await websocket.accept()
    websocket_connections.append(websocket)
    position = {}
    try:
        while True:
            await asyncio.sleep(1)
            try:
                # position = get_actual_position()
                message={
                    "onload": False,
                    "day": True,
                    "temp": f'{ts.read_once()}',
                    "humidity": f'{random.randint(10,100)}',
                    "uv_index": f'{random.randint(1,12)}',
                    "rain": False,
                    "atmospheric_pressure": f'{random.randint(1000,2000)}'
                }
            # message = f"This is a message from the server at {datetime.utcnow()}"
                await websocket.send_text(json.dumps({**message, **position}))
            except Exception as error:
                print(f'error: {error}')
    except WebSocketDisconnect:
        websocket_connections.remove(websocket)

@router.get("/", response_class=HTMLResponse)
async def get():
    return HTMLResponse(content=html_content)
