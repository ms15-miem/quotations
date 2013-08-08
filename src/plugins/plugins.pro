TEMPLATE = subdirs

# Needed to ensure that things are built right, which you have to do yourself :(
CONFIG += ordered

# All the projects in your application are sub-projects of your solution
SUBDIRS += \
    InternetPoster\
    DiaryPoster\


# Use .depends to specify that a project depends on another.
DiaryPoster.depends = InternetPoster
