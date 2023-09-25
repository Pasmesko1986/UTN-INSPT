import { useState, useEffect } from 'react';
import { Chart, Line } from 'react-chartjs-2';


const LineChart = (props) => {
    const [chartData, setChartData] = useState(null);

    useEffect(() => {
      if (!chartData) {
        // Crear y configurar los datos del gráfico solo si aún no existe
        const data = {
          labels: ['Enero', 'Febrero', 'Marzo', 'Abril', 'Mayo'],
          datasets: [
            {
              label: 'Ventas Mensuales',
              data: [12, 19, 3, 5, 2],
              borderColor: 'rgba(75, 192, 192, 1)',
              borderWidth: 2,
              fill: false,
            },
          ],
        };
        
        setChartData(data);
      }
    }, [chartData]);
    
    if (!chartData) {
      return null; // Evita renderizar el gráfico hasta que los datos estén listos
    }
    
    const options = {
      scales: {
        x: {
          beginAtZero: true,
        },
        y: {
          beginAtZero: true,
        },
      },
    };
    
    return (
      <div>
        <h2>Gráfico de Línea</h2>
        <Line data={chartData} options={options} />
      </div>
    );
}

export default LineChart;