import uvicorn
from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
# from wheater_station.core.db.create_schemas import create_all_schemas
from apis.v1_application_apis import router as application_apis
from apis.v1_sockets import router as socket_apis
from settings import (
    ENVIRONMENT,
    HOST,
    PORT)

description = f'''<a href="https://github.com/Pasmesko1986/UTN-INSPT">
    <img width=5% src="https://github.com/Pasmesko1986/UTN-INSPT/blob/main/backend/wheater_station/wheater_station/core/assets/inspt_logo.png?raw=true"/> Follow the repository...</a>'''

app = FastAPI(
    title="Wheater Station API service docs page",
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
app.include_router(socket_apis)


if __name__ == "__main__":
    uvicorn.run(
        'main:app',
        host=HOST,
        port=PORT,
        reload=True if ENVIRONMENT =='develop' else False
        )
