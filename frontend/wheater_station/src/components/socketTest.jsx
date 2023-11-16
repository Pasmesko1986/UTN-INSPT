import { useEffect, useState } from 'react';

function WebSocketComponent() {
  const [message, setMessage] = useState('');

  useEffect(() => {
    // Establecer la conexión WebSocket cuando se monta el componente
    const socket = new WebSocket('ws://localhost:8082/ws');

    // Manejar mensajes entrantes del WebSocket
    socket.onmessage = (event) => {
      setMessage(event.data);
    };

    // Manejar errores de WebSocket
    socket.onerror = (error) => {
      console.error('WebSocket error:', error);
    };

    // Cerrar la conexión WebSocket cuando el componente se desmonta
    return () => {
      socket.close();
    };
  }, []);

  return (
    <div>
      <h1>WebSocket Data</h1>
      <p>Server Time: {message}</p>
    </div>
  );
}

export default WebSocketComponent;