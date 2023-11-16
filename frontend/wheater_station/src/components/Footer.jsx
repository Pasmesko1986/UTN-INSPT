import { Grid } from "@mui/material";
import Avatar from '@mui/material/Avatar';
import insptLogo from '../assets/inspt_radio_logo.png';

export default function Footer() {
  return (
  <Grid >
    <Avatar alt="UTN-INSPT" src={insptLogo} sx={{ width: 80, height: 80 }} />
  </Grid>

  );
}