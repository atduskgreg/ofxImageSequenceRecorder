## ofxImageSequenceRecorder

A threaded image sequence recorder for OpenFrameworks. Adapted from the ideas of Memo and others in [this forum thread](http://forum.openframeworks.cc/index.php?topic=1687.0).

This version maintains a queue of ofPixels objects to be saved. You can add a frame from an ofVideoGrabber, an ofImage, an ofVideoPlayer, or anything else that provides an ofPixels object. While the thread is running, frames are saved off to disk in the same order they were added with sequential filenames based on the file prefix and format your provided.

See the included example for usage.

