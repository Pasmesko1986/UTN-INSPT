import { useState } from 'react'
import './App.css'
import NestedGrid from './pages/Dashboard'
function App() {
  const [count, setCount] = useState(0)

  return (<>
    <NestedGrid />

  </>
  )
}

export default App
