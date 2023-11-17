import AppBar from '@mui/material/AppBar';
import Box from '@mui/material/Box';
import Toolbar from '@mui/material/Toolbar';
import Typography from '@mui/material/Typography';
import WifiIcon from '@mui/icons-material/Wifi';
import { useState, useContext } from "react";
import { StreamingDataContext } from '../App';

export default function Header() {
  const { streamingData, setStreamingData } = useContext(StreamingDataContext);
  const connectionColor = streamingData?.onload ? '#FF6E95': '#9BDE7E'
  return (
    <Box sx={{ flexGrow: 1, }}>
      <AppBar position="static" sx={{background: '#2F4858', marginBottom:2}}>
        <Toolbar>
          <Typography variant="h6" component="div" sx={{ flexGrow: 1 }}>
            Wheather Station Live <WifiIcon sx={{fontSize:30, color:connectionColor}}/>
          </Typography>
        </Toolbar>
      </AppBar>
    </Box>
  );
}