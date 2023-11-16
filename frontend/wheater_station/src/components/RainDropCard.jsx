import Card from '@mui/material/Card';
import CardContent from '@mui/material/CardContent';
import Typography from '@mui/material/Typography';
import { CardActionArea } from '@mui/material';
import DeviceThermostatIcon from '@mui/icons-material/DeviceThermostat';
import Lottie from "lottie-react";
import sun from '../assets/lottie_animations/sun.json';
export default function RainDrop() {
  return (
    <Card sx={{ maxWidth: 345 }}>
      <CardActionArea>
          <CardContent>
          <Typography gutterBottom variant="h3" component="div">
          <DeviceThermostatIcon /> Rain status
          </Typography>
          <Lottie animationData={sun} loop={true} />
        </CardContent>
      </CardActionArea>
    </Card>
  );
}