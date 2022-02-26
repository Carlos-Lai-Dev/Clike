using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;


public class Ball : MonoBehaviour
{
    public Text scoreText;
    //public Text winText;
    public float F = 0;
    public Rigidbody rd;
    private int n = 0;
    public GameObject PausePanel;
    //public int j =1;
    public AudioSource scoreAudio;
    //public AudioSource wonGame;
    public AudioSource bgm;
    //private int X=1;
    public GameObject pauseButton;

    public GameObject video1;
    public GameObject video2;
    public GameObject video3;
    public GameObject video4;
    public GameObject video5;
    public GameObject video6;
    public GameObject video7;
    public GameObject video8;
    public GameObject video9;
    public GameObject video10;
    public GameObject video11;
    

    // Start is called before the first frame update
    void Start()
    {
        rd = GetComponent<Rigidbody>();
        
            bgm.Play();
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Time.timeScale == 1)
        {
            float h = Input.GetAxisRaw("Horizontal");
            float v = Input.GetAxisRaw("Vertical");
            //float j = Input.GetAxis("Jump");
            rd.AddForce(new Vector3(h, 0, v) * F);

        }


        if (Time.timeScale == 1f && Input.GetKeyDown(KeyCode.Escape))
        {

            bgm.Pause();

            PausePanel.SetActive(true);
            Time.timeScale =0f;
            pauseButton.SetActive(false);
           
        }
        else
        {
            if (Time.timeScale == 0f && Input.GetKeyDown(KeyCode.Escape))


            { 

            PausePanel.SetActive(false);
            Time.timeScale = 1f;

                bgm.Play();
                
                pauseButton.SetActive(true);

                video1.SetActive(false);

                video2.SetActive(false);

                video3.SetActive(false);

                video4.SetActive(false);

                video5.SetActive(false);

                video6.SetActive(false);

                video7.SetActive(false);

                video8.SetActive(false);

                video9.SetActive(false);

                video10.SetActive(false);

                video11.SetActive(false);


            }


        }

    }




    private void OnCollisionEnter(Collision collision)
    {

        if (collision.gameObject.tag == "Food")
        {
            Destroy(collision.gameObject);

        }

    }

    private void OnTriggerEnter(Collider collider)
    {
        if (collider.gameObject.tag == "Food")
        {
            Destroy(collider.gameObject);
            n++;
            scoreText.text = "Score: " + n;

            scoreAudio.Play();

            //x++;

            if (n == 12)
            {
                //winText.text = "You won!";

                //wonGame.Play();

                SceneManager.LoadScene("End");
            }





            pauseButton.SetActive(false);
            bgm.Pause();
            Time.timeScale = 0f;


            if (n == 1)
            {
                video1.SetActive(true);
            }

            if (n == 2)
            {
                video2.SetActive(true);
            }
            if (n == 3)
            {
                video3.SetActive(true);
            }
            if (n == 4)
            {
                video4.SetActive(true);
            }

            if (n == 5)
            {
                video5.SetActive(true);
            }

            if (n == 6)
            {
                video6.SetActive(true);
            }


            if (n == 7)
            {
                video7.SetActive(true);
            }


            if (n == 8)
            {
                video8.SetActive(true);
            }

            if (n == 9)
            {
                video9.SetActive(true);
            }


            if (n == 10)
            {
                video10.SetActive(true);
            }


            if (n == 11)
            {
                video11.SetActive(true);
            }

        }

    }
   




}
    






