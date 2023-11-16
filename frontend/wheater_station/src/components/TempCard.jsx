import Card from '@mui/material/Card';
import CardContent from '@mui/material/CardContent';
import Typography from '@mui/material/Typography';
import { CardActionArea } from '@mui/material';
import DeviceThermostatIcon from '@mui/icons-material/DeviceThermostat';
import WaterDropIcon from '@mui/icons-material/WaterDrop';

import * as React from 'react';
import Box from '@mui/material/Box';
import Paper from '@mui/material/Paper';
import Grid from '@mui/material/Grid';

export default function TempCard() {
  return (
    <Grid sx={{display: 'flex', justifyContent: 'center', alignItems:'center'}}>
      <Grid >
        <DeviceThermostatIcon sx={{fontSize:100}}/>
      </Grid>
      <Grid>

        <Typography gutterBottom variant="h3" component="div"> Temperature</Typography>
      </Grid>

      <Grid>

        <Typography variant="h1"> 32°C </Typography>
      </Grid>

    </Grid>
  );
}