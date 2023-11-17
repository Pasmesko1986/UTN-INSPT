import * as React from 'react';
import AppBar from '@mui/material/AppBar';
import Box from '@mui/material/Box';
import Toolbar from '@mui/material/Toolbar';
import Typography from '@mui/material/Typography';
import PlaceIcon from '@mui/icons-material/Place';
import { useState, useContext } from "react";
import { StreamingDataContext } from '../App';
import PublicIcon from '@mui/icons-material/Public';

export default function Location() {
    const { streamingData, setStreamingData } = useContext(StreamingDataContext);
    if (streamingData?.country){
        return (
            <Box sx={{ flexGrow: 1, textAlign:'start', margin: 3}}>
            <Typography variant="h6" component="div">
                <PlaceIcon sx={{ fontSize: 30, color: 'white' }} />
                {` ${streamingData?.city}`}

            </Typography>
            <Typography variant="h6" component="div" >
                <PublicIcon sx={{ fontSize: 30, color: 'white' }} />
                {` ${streamingData?.state}`}
                {` ${streamingData?.country}`}
            </Typography>
        </Box>
    );
    }else{
        return <></>
    }
}