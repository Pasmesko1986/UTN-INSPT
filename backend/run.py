import uvicorn
# from wheater_station.wheater_station.main import app
# from wheater_station.wheater_station.settings import (
#     ENVIRONMENT,
#     HOST,
#     PORT)

if __name__ == "__main__":
    # args = parser.parse_args()
    # print(args.createschemas)
    # if args.createschemas:
    #     create_all_schemas()
    
    uvicorn.run(
        'wheater_station.wheater_station.main:app',
        reload=True
        )