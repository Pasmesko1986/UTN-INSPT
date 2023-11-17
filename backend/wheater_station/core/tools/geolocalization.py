import geocoder

def get_actual_position():
    # Obtiene la localización actual basada en la dirección IP
    loc = geocoder.ip('me')
    return {
        "country": f'{loc.country}',
        "state": f'{loc.state}',
        "city": f'{loc.city}',
        "lat": f'{loc.latlng[0]}',
        "lon": f'{loc.latlng[1]}'
    }