FROM python:3.9-slim

LABEL name=wheater_station

# Setup env
ENV LANG C.UTF-8
ENV LC_ALL C.UTF-8
ENV PYTHONDONTWRITEBYTECODE 1
ENV PYTHONFAULTHANDLER 1

SHELL ["/bin/bash", "-c"]

# Install poetry and compilation dependencies
RUN apt-get update && apt-get install -y 
RUN pip install --upgrade pip
RUN apt-get install libpq-dev python-dev-is-python3 -y
RUN apt-get install gcc -y
RUN apt-get clean
RUN rm -rf /var/lib/apt/lists/*

# Install python dependencies in /.venv
COPY requirements.txt ./
RUN pip install -r requirements.txt

# Create and switch to a new user

# Install application into container
COPY . ./app
WORKDIR /app

EXPOSE 8020
EXPOSE 5432
CMD python startup.py