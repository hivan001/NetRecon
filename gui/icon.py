import sys
import random
import copy
from PIL import Image
from PySide6 import QtCore, QtWidgets, QtGui

class Icon(QtWidgets.QGraphicsView):
    image_items = []
    def __init__(self):
        super().__init__()

        pc_path = "static/pc.png"
        ad_path = "static/ad.png"
        db_path = "static/db.png"
        web_path = "static/web.png"

        #resizing images for standardization
        image_paths = [pc_path, ad_path, db_path, web_path]

        for image_path in image_paths:
            image = Image.open(image_path)
            width = 300
            height = 400
            resize = image.resize((width,height))
            resize.save(image_path)


        pc_pixmap = QtGui.QPixmap(pc_path)
        ad_pixmap = QtGui.QPixmap(ad_path)
        db_pixmap = QtGui.QPixmap(db_path)
        web_pixmap = QtGui.QPixmap(web_path)

        pc_image_item = QtWidgets.QGraphicsPixmapItem(pc_pixmap)
        ad_image_item = QtWidgets.QGraphicsPixmapItem(ad_pixmap)
        db_image_item = QtWidgets.QGraphicsPixmapItem(db_pixmap)
        web_image_item = QtWidgets.QGraphicsPixmapItem(web_pixmap)

        self.image_items.append(pc_image_item)
        self.image_items.append(ad_image_item)
        self.image_items.append(db_image_item)
        self.image_items.append(web_image_item)
       


    def make_pc_icon(self):
        pixmap = self.image_items[0].pixmap()
        pc = QtWidgets.QGraphicsPixmapItem(pixmap)
        return pc
    
    def make_ad_icon(self):
        pixmap = self.image_items[1].pixmap()
        ad = QtWidgets.QGraphicsPixmapItem(pixmap)
        return ad
    
    def make_db_icon(self):
        pixmap = self.image_items[2].pixmap()
        db = QtWidgets.QGraphicsPixmapItem(pixmap)
        return db
    
    def make_web_icon(self):
        pixmap = self.image_items[3].pixmap()
        web = QtWidgets.QGraphicsPixmapItem(pixmap)
        return web
    







    #Logic to extract data from results



        

    