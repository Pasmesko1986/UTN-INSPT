import { Grid } from "@mui/material";
import Avatar from '@mui/material/Avatar';
import insptLogo from '../assets/inspt_radio_logo.png';
import { useState, useContext } from "react";
import { StreamingDataContext } from '../App';

export default function Footer() {
  const { streamingData, setStreamingData } = useContext(StreamingDataContext);

  return (
  <Grid >
    <Avatar alt="UTN-INSPT" src={insptLogo} sx={{ width: 80, height: 80 }} />
  </Grid>

  );
}