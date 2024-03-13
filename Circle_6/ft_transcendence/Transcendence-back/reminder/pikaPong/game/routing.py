
from django.urls import re_path

from . import consumers

websocket_urlpatterns = [
    re_path('multiPong/', consumers.PongConsumer.as_asgi()),
]