import Typography from '@mui/material/Typography';
import WbSunnyIcon from '@mui/icons-material/WbSunny';
import Grid from '@mui/material/Grid';

const BORDER = null
// const BORDER = '1px solid red'

export default function IndexUVCard() {
  return (
    <Grid sx={{
      border:BORDER, maxWidth:120,
      justifyContent: 'center',
      alignItems:'center',
      background: 'rgba(0, 0, 0, 0.11)',
      borderRadius: 3,
      margin:1,
      padding:1.5

    }}
    container spacing={2}>
      <Grid sx={{border:BORDER}}>
        <WbSunnyIcon sx={{fontSize:40}}/>
      </Grid>
      <Grid sx={{border:BORDER}}>

        <Typography variant="h4"> Low </Typography>
        <Typography gutterBottom variant="h7" component="div"> UV Index</Typography>
      </Grid>

    </Grid>
  );
}