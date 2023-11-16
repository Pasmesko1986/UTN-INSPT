import * as React from 'react';
import AppBar from '@mui/material/AppBar';
import Box from '@mui/material/Box';
import Toolbar from '@mui/material/Toolbar';
import Typography from '@mui/material/Typography';
import Button from '@mui/material/Button';
import IconButton from '@mui/material/IconButton';
import WifiIcon from '@mui/icons-material/Wifi';

export default function Header() {
  return (
    <Box sx={{ flexGrow: 1, }}>
      <AppBar position="static" sx={{background: '#2F4858', marginBottom:2}}>
        <Toolbar>
          <Typography variant="h6" component="div" sx={{ flexGrow: 1 }}>
            Wheather Station Live <WifiIcon sx={{fontSize:30, color:'red'}}/>
          </Typography>
        </Toolbar>
      </AppBar>
    </Box>
  );
}