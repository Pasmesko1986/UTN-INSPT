import Typography from '@mui/material/Typography';
import SpeedIcon from '@mui/icons-material/Speed';
import Grid from '@mui/material/Grid';

const BORDER = null
// const BORDER = '1px solid red'

export default function AtmosphericPressureCard() {
  return (
    <Grid sx={{
      border:BORDER, maxWidth:200,
      justifyContent: 'center',
      alignItems:'center',
      background: 'rgba(0, 0, 0, 0.11)',
      borderRadius: 3,
      margin:1,
      padding:1
    }}
    container spacing={2}>
      <Grid sx={{border:BORDER}}>
        <SpeedIcon sx={{fontSize:40}}/>
      </Grid>
      <Grid sx={{border:BORDER}}>

        <Typography variant="h4"> 1019mb </Typography>
        <Typography gutterBottom variant="h7" component="div"> Atmospheric pressure</Typography>
      </Grid>

    </Grid>
  );
}