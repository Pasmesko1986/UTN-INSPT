from wheater_station.core.db.charts import Chart

ALLOWED_ENTITIES = {
        'chart':Chart,
        }

def create_all_schemas():
    Chart.__create_all_schemas__()