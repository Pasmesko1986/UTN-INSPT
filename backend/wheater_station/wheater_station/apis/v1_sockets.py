from fastapi import APIRouter, WebSocket, WebSocketDisconnect
from fastapi.responses import HTMLResponse
import asyncio
from datetime import datetime
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

    try:
        while True:
            await asyncio.sleep(0.03)

            message = f"This is a message from the server at {datetime.utcnow()}"
            await websocket.send_text(message)
    except WebSocketDisconnect:
        websocket_connections.remove(websocket)

@router.get("/", response_class=HTMLResponse)
async def get():
    return HTMLResponse(content=html_content)
