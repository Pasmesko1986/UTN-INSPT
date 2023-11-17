import Typography from '@mui/material/Typography';
import WaterDropIcon from '@mui/icons-material/WaterDrop';import Grid from '@mui/material/Grid';
import { useState, useContext } from "react";
import { StreamingDataContext } from '../App';

const BORDER = null
// const BORDER = '1px solid red'

export default function HumidityCard() {
  const {streamingData, setStreamingData} = useContext(StreamingDataContext);

  return (
    <Grid sx={{
      border:BORDER, maxWidth:120,
      justifyContent: 'center',
      alignItems:'center',
      background: 'rgba(0, 0, 0, 0.11)',
      borderRadius: 3,
      margin:1,
      padding:1
    }}
    container spacing={2}>
      <Grid sx={{border:BORDER}}>
        <WaterDropIcon sx={{fontSize:40}}/>
      </Grid>
      <Grid sx={{border:BORDER}}>

        <Typography variant="h4"> {streamingData?.humidity}% </Typography>
        <Typography gutterBottom variant="h7" component="div"> Humidity</Typography>
      </Grid>

    </Grid>
  );
}