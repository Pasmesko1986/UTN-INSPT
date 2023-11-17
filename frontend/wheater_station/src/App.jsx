import './App.css'
import { useState, useEffect, createContext } from "react";
import { Grid } from '@mui/material'
import NestedGrid from './pages/Dashboard'
import Header from './components/Header'
import Footer from './components/Footer'
import { defaultStreamingValues } from './dataExample';
import LoadingSpinner from './components/Loading';

export const StreamingDataContext = createContext();

function App() {
  const [streamingData, setStreamingData] = useState(defaultStreamingValues);

  useEffect(() => {
    // Establecer la conexión WebSocket cuando se monta el componente
    
    const socket = new WebSocket('ws://localhost:8082/ws');
    
    // Manejar mensajes entrantes del WebSocket
    socket.onmessage = (event) => {
      setStreamingData(JSON.parse(event.data));
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
  return (<>
    <StreamingDataContext.Provider value={{streamingData, setStreamingData}}>
      {streamingData?.onload ? <LoadingSpinner/> : <></>}
      <Grid sx={{ minHeight: '100Vh' }}>
        <Grid sx={{ minHeight: '80Vh' }}>
          <Header />
          <NestedGrid />
        </Grid>
        <Grid sx={{ minHeight: '10Vh', display: 'flex', justifyContent: 'flex-end', alignItems: 'center' }}>
          <Footer />
        </Grid>
      </Grid>
    </StreamingDataContext.Provider>
  </>
  )
}

export default App
