package pl.lukesawicki;

import java.awt.EventQueue;

import javax.swing.JFrame;

public class YasRenderer {

	private JFrame frame;
	public static final int WINDOW_WIDTH = 640;
	public static final int WINDOW_HEIGHT = 480;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					YasRenderer window = new YasRenderer();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public YasRenderer() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.pack();
		frame.setBounds(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.add(new Renderer(WINDOW_WIDTH, WINDOW_HEIGHT));
	}

}
