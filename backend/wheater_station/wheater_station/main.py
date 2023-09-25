import uvicorn
import argparse
from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
from wheater_station.wheater_station.core.database.create_schemas import create_all_schemas
from wheater_station.wheater_station.apis.v1_application_apis import router as application_apis
from wheater_station.wheater_station.settings import (
    ENVIRONMENT,
    HOST,
    PORT)

parser = argparse.ArgumentParser()
parser.add_argument('--createschemas', type=bool, required=False)

description = f'''<a href="https://github.com/Pasmesko1986/UTN-INSPT">
    <img width=10% src="https://raw.githubusercontent.com/HectorInove/g-challenge/develop/wheater_station/wheater_station/src/docs/assets/octocat.gif"/> Follow the repository...</a>'''

app = FastAPI(
    title="G-challenge API service docs page",
    description=description,
)
origins = ["*"]

app.add_middleware(
    CORSMiddleware,
    allow_origins=origins,
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

app.include_router(application_apis)



if __name__ == "__main__":
    args = parser.parse_args()
    print(args.createschemas)
    if args.createschemas:
        create_all_schemas()
    
    uvicorn.run(
        'main:app',
        host=HOST,
        port=PORT,
        reload=True if ENVIRONMENT =='develop' else False
        )
