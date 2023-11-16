import './App.css'
import { useState, useEffect, createContext, useContext } from "react";
import { Grid } from '@mui/material'
import NestedGrid from './pages/Dashboard'
import Header from './components/Header'
import Footer from './components/Footer'

const BORDER = '1px solid red'

const DataContext = createContext();

function App() {
  const [data, setData] = useState({ onload: true });


  return (<>
    <DataContext.Provider value={data}>
      <Grid sx={{ minHeight: '100Vh', border: BORDER }}>
        <Grid sx={{ minHeight: '80Vh' }}>
          <Header />
          <NestedGrid />
        </Grid>
        <Grid sx={{ border: BORDER, minHeight: '10Vh', display: 'flex', justifyContent: 'flex-end', alignItems: 'center' }}>
          <Footer />
        </Grid>
      </Grid>
    </DataContext.Provider>

  </>
  )
}

export default App
