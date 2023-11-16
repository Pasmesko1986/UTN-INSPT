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
import HumidityCard from '../components/HumidityCard';
import IndexUVCard from '../components/IndexUVCard';
import AtmosphericPressureCard from '../components/AtmosphericPressureCard';

const BORDER = null
// const BORDER = '1px solid red'

export default function NestedGrid() {
    return (
        <Box sx={{ flexGrow: 1 , border:BORDER}}>
            <Grid container spacing={2} >
                <Grid container item spacing={1} >
                <TempCard />
                </Grid>
                <Grid container item spacing={2} sx={{margin:1}}>
                                <HumidityCard/>
                                <IndexUVCard/>
                                <AtmosphericPressureCard/>
                </Grid>
            </Grid>
        </Box>
    );
}