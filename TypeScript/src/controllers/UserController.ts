import { Request, Response } from 'express'
import EmailService from '../services/EmailService'

const users = [
    { name: 'Lucas', email: '@gmail.com' },
    { name: 'Travis', email: '@yahoo.com' }
]

export default {
    index: async (req: Request, res: Response) => {
        return res.json(users)
    },

    create: async (req: Request, res: Response) => {
        const emailService = new EmailService()
        return res.send(emailService.sendMail(
            {
                to: { name: 'Lucas', email: '@gmail.com' },
                message: { subject: 'Welcome', body: 'hey!' }
            }
        )
        )
    }
}