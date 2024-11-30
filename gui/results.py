import sys
import random
import copy
import icon
import json
from PIL import Image
from PySide6 import QtCore, QtWidgets, QtGui

class Results():
    def __init__(self):
        self.images = icon.Icon()
    


    def get_results(self):
        try:
            f = open("../results/results.json", "r")
            data=json.load(f)
        except:
            print("Unable to open Results.json")

        return data


    def plot_results(self, scene):
        image_x = 10
        image_y = 50
        #Return icons in squares of 6
        square_count = 0

        data = self.get_results()
        for i in data["IPs"]:
            pc = self.images.make_pc_icon()
            pc.setScale(0.25)
            pc.setPos(image_x,image_y)
            pc.setFlags(QtWidgets.QGraphicsPixmapItem.GraphicsItemFlag.ItemIsMovable | QtWidgets.QGraphicsPixmapItem.GraphicsItemFlag.ItemIsSelectable |
                            QtWidgets.QGraphicsPixmapItem.GraphicsItemFlag.ItemClipsToShape)
            scene.addItem(pc)
 
            if square_count == 0:  # Start new square
                image_x += 50
                square_count += 1
            elif square_count < 2:  # Continue horizontally
                image_x += 50
                square_count += 1
            elif square_count == 2:  # Drop down vertically
                image_y += 100
                square_count += 1
            elif square_count < 5:  # Move back horizontally
                image_x -= 50
                square_count += 1
            elif square_count == 5:  # Reset and move to new square group
                square_count = 0
                image_x += 200  # Move to the next grid's starting position
                image_y = 0  # Reset vertical position for the new square group
        
