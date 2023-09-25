from fastapi import APIRouter
from wheater_station.wheater_station.core.database.db_connect import db_health
from wheater_station.wheater_station.core.database.charts import Chart
from wheater_station.wheater_station.apis.v1_schemas import InsertChartData

router = APIRouter()

@router.get("check-health/", tags=["test"])
def check_database_health():
    return db_health()

@router.get("/records/{type}", tags=["📈 Chart APIs"])
async def get_chart_records(type: str, time_lapse_minutes: int):
    '''
    <p>
    Esta API se utiliza para recuperar los datos de cada grafico de manera
    independiente.

    ```
    Parametros de entrada:

    type: es el tipo de gráfico.

    time_lapse_minutes: es la ventana de tiempo en minutos que queremos obtener.
    ```


    Si time_lapse_minutes = 0, entonces nos va a traer el último registro para el grafico seleccionado.
    </p>
    '''
    result = await Chart.get_chart_data(
        chart_type=type,
        time_lapse_minutes=time_lapse_minutes
        )
    return result


@router.post("/raw-data/", tags=["📈 Chart APIs"])
async def insert_chart_data(body_params : InsertChartData):
    '''
    <h3>Parametros de entrada:</h3>

        [
            {
            "type": str,
            "data": dict
            },
        ]

    <h3>Estructura de salida:</h3>

        {
        "valids": [
            {
            "type": str,
            "data": dict
            }
        ],
        "invalids": []
        }
    '''
    result = await Chart.insert_record(**body_params.model_dump())
    return result
