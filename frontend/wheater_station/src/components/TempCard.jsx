import Typography from '@mui/material/Typography';
import DeviceThermostatIcon from '@mui/icons-material/DeviceThermostat';
import Lottie from "lottie-react";
import sun from '../assets/lottie_animations/sun.json';
import moon from '../assets/lottie_animations/clearMoon.json'
import Grid from '@mui/material/Grid';

const BORDER = null
// const BORDER = '1px solid red'

export default function TempCard() {
  const dayNight= false
  const dayBackground = 'linear-gradient(180deg, #ACCFFF 0%, #5591E0 100%)';
  const nightBackground = 'linear-gradient(50deg,  #130938, #190b41, #200a4a, #290953, #32055c)';
  document.body.style.background = dayNight ? dayBackground : nightBackground;

  return (
    <Grid sx={{justifyContent: 'flex-end', alignItems:'center', border:BORDER, minWidth:100, margin: 1}}
    container spacing={2}>
      <Grid sx={{border:BORDER, margin:1}}>
        <DeviceThermostatIcon sx={{fontSize:50}}/>
      </Grid>
      <Grid sx={{border:BORDER}}>

        <Typography variant="h3"> 32°C </Typography>
        <Typography gutterBottom variant="h6" component="div"> Temperature</Typography>
      </Grid>

    <Grid sx={{border:BORDER, maxWidth:100}}>
    {dayNight?
    <Lottie animationData={sun} loop={true} />:
    <Lottie animationData={moon} loop={true} style={{transform:'scaleX(-1)'}} /> }

    </Grid>
    </Grid>
  );
}