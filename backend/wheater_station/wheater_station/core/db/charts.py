from sqlalchemy import insert, func
from datetime import datetime, timedelta
from sqlalchemy import Column, Integer, String, DateTime, JSON
from core.db.db_connect import (
    ENGINE,
    BASE,
    SESSION,
    excecute
)

class Chart(BASE):
    __tablename__ = 'charts'

    id = Column(Integer, primary_key=True, autoincrement=True,)
    type = Column(String)
    data = Column(JSON)
    timestamp = Column(DateTime, default=datetime.utcnow)

    @staticmethod
    def __delete_schema__():
        '''Delete table'''
        BASE.metadata.tables['charts'].drop(ENGINE)

    @staticmethod
    def __create_all_schemas__():
        '''Create table'''
        BASE.metadata.create_all(ENGINE)

    @staticmethod
    async def insert_record(type: str, data:dict):
        result = {'valids':[], 'invalids':[]}
        obj = {'type': type, 'data': data}
        to_insert =[]
        try:
            stmt = insert(Chart).values(**obj).returning(Chart)
            query_result = excecute(stmt).fetchone()
            to_insert.append({
                'id':int(query_result[0]),
                'type':str(query_result[1]),
                'data':str(query_result[2]),
                'timestamp':str(query_result[3])
                }
            )
        except Exception as e:
            result['invalids'].append(obj)
        result['valids'] = to_insert
        return result

    @staticmethod
    async def get_chart_data(chart_type: str, time_lapse_minutes: int = 30):
        session = SESSION()
        if time_lapse_minutes == 0:
            last_chart = session.query(Chart).filter(
                Chart.type == chart_type).order_by(
                    Chart.timestamp.desc()).first()
            return last_chart
        # Encuentra el último timestamp en la base de datos
        latest_timestamp = session.query(func.max(Chart.timestamp)).scalar()
        if latest_timestamp is not None:
            # Calcula el límite de tiempo para la consulta
            thirty_minutes_ago = latest_timestamp - timedelta(minutes=time_lapse_minutes)
            # Realiza la consulta para seleccionar registros con el tipo de
            #  gráfico "chart_type" y timestamp dentro de los últimos 30 minutos
            results = session.query(Chart).filter(Chart.type == chart_type, Chart.timestamp >= thirty_minutes_ago).all()
            # Itera sobre los resultados
            for chart in results:
                print(f"ID: {chart.id}, Type: {chart.type}, Timestamp: {chart.timestamp}")
        else:
            print("No hay registros en la base de datos.")
        return results
