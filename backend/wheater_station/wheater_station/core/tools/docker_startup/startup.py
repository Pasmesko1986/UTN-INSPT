import os
import uvicorn
from wheater_station.main import app
from wheater_station.core.db.create_schemas import create_all_schemas

if __name__ == "__main__":
    create_all_schemas()
    uvicorn.run(
        app,
        host=os.getenv('HOST'),
        port=int(os.getenv('PORT')),
        )