import * as React from 'react';
import { styled } from '@mui/material/styles';
import Box from '@mui/material/Box';
import Paper from '@mui/material/Paper';
import Grid from '@mui/material/Grid';
import { ResponsiveContainer } from 'recharts';
import Test from '../components/lineChartTest'
import ActionAreaCard from '../components/Card';
// sensor cards:
import TempCard from '../components/TempCard';
import RainDrop from '../components/RainDropCard';


function FormRow() {
    return (
        <React.Fragment>
            <Grid item xs={4}>
                {/* <ResponsiveContainer width="100%" height="100%">
      <Test/>
      
</ResponsiveContainer>  */}
                {/* <WebSocketComponent/> */}
                <TempCard />
            </Grid>
            <Grid item xs={4}>
                <RainDrop />
            </Grid>
            <Grid item xs={4}>
                <ActionAreaCard />

            </Grid>
        </React.Fragment>
    );
}

export default function NestedGrid() {
    return (
        <Box sx={{ flexGrow: 1 }}>
            <Grid container spacing={1}>
                <Grid container item spacing={3}>
                <TempCard />
                </Grid>
                {/* <Grid container item spacing={3}>
                    <FormRow />
                </Grid>
                <Grid container item spacing={3}>
                    <FormRow />
                </Grid> */}
            </Grid>
        </Box>
    );
}