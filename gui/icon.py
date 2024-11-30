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
        pc_x_pos = pc.pos().x()
        pc_y_pos = pc.pos().y()
        pc_width = pixmap.width()

        # Create a QWidget with a layout for the toggle button
        pc_widget = QtWidgets.QWidget()
        pc_widget.layout = QtWidgets.QVBoxLayout(pc_widget)

        pc_widget.toggle_button = QtWidgets.QPushButton("IP Address: ")
        pc_font = QtGui.QFont("Arial", 30)
        pc_widget.toggle_button.setFont(pc_font)
        pc_widget.toggle_button.setCheckable(True)
        pc_widget.toggle_button.setChecked(False)
        pc_widget.toggle_button.setFixedSize(400, 100)
        pc_widget.layout.addWidget(pc_widget.toggle_button)

        # Proxy widget for the toggle button
        toggle_button = QtWidgets.QGraphicsProxyWidget()
        toggle_button.setWidget(pc_widget)
        toggle_button.setPos(pc_x_pos + pc_width, pc_y_pos)

        # Create content area as a separate QWidget
        content_widget = QtWidgets.QWidget()
        content_layout = QtWidgets.QVBoxLayout(content_widget)
        content_label = QtWidgets.QLabel("TCP Ports")
        content_font = QtGui.QFont("Arial", 20)
        content_label.setFont(content_font)
        content_label.setAlignment(QtCore.Qt.AlignTop | QtCore.Qt.AlignLeft)
        content_widget.setFixedSize(400, 800)
        content_layout.addWidget(content_label)

        # Proxy widget for the content area
        content_x_pos = toggle_button.pos().x()
        content_y_pos = toggle_button.pos().y() + 150
        content = QtWidgets.QGraphicsProxyWidget()
        content.setWidget(content_widget)
        content.setPos(content_x_pos, content_y_pos)  # Adjusted position

        # Group all items
        group = QtWidgets.QGraphicsItemGroup()
        group.addToGroup(pc)
        group.addToGroup(toggle_button)
        group.addToGroup(content)

        return group

    
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




        

    